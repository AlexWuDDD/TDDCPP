#include "WavReader.h"
#include "WavDescriptor.h"

#include <iostream>
#include <cstring>
#include <cstdint>
#include <algorithm>

#include "rlog/rlog.h"
#include "rlog/StdioNode.h"

bool hasExtension(const std::string& filename, const std::string& substring)
{
    std::string ext{"." + substring};
    if(ext.length() > filename.length()) return false;
    return 0 == filename.compare(filename.length() - ext.length(), ext.length(), ext);
}

struct RiffHeader
{
    int8_t id[4];
    uint32_t length;
    int8_t format[4];
};

struct FormatSubchunkHeader
{
    int8_t id[4];
    uint32_t subchunkSize;
};

struct FormatSubchunk
{
    uint16_t formatTag;
    uint16_t channels;
    uint32_t samplesPerSecond;
    uint32_t averageBytesPerSecond;
    uint16_t blockAlign;
    uint16_t bitsPerSample;
};

struct FactOrData
{
    int8_t tag[4];
};

struct DataChunk
{
    uint32_t length;
};

struct FactChunk
{
    uint32_t chunkSize;
    uint32_t samplesPerChannel;
};

WavReader::WavReader(const std::string& source, const std::string& dest)
    : m_source(source)
    , m_dest(dest)
{
    m_descriptor = new WavDescriptor(dest);

    channel = DEF_CHANNEL("info/wav", rlog::Log_Debug);
    log.subscribeTo((rlog::RLogNode*)RLOG_CHANNEL("info/wav"));
    rLog(channel, "reading from %s writing to %s", source.c_str(), dest.c_str());
}

WavReader::~WavReader()
{
    delete m_descriptor;
    delete channel;
}

void WavReader::publishSnippets() {
   boost::filesystem::directory_iterator itEnd; 
   for (boost::filesystem::directory_iterator it(m_source); it != itEnd; ++it) 
      if (!is_directory(it->status()) && 
          hasExtension(it->path().filename().string(), "wav"))
        open(it->path().filename().string(), false);
}

std::string WavReader::toString(int8_t* bytes, unsigned int size) {
   return std::string{(char*)bytes, size};
}

void WavReader::open(const std::string& name, bool trace) {
   rLog(channel, "opening %s", name.c_str());

   std::ifstream file{name, std::ios::in | std::ios::binary};
   if (!file.is_open()) {
      rLog(channel, "unable to read %s", name.c_str());
      return;
   }

   std::ofstream out{m_dest + "/" + name, std::ios::out | std::ios::binary};

   RiffHeader header;
   file.read(reinterpret_cast<char*>(&header), sizeof(RiffHeader));

   if (toString(header.id, 4) != "RIFF") {
      rLog(channel, "ERROR: %s is not a RIFF file",
         name.c_str());
      return;
   }
   if (toString(header.format, 4) != "WAVE") {
      rLog(channel, "ERROR: %s is not a wav file: %s",
         name.c_str(),
         toString(header.format, 4).c_str());
      return;
   }
   out.write(reinterpret_cast<char*>(&header), sizeof(RiffHeader));

   FormatSubchunkHeader formatSubchunkHeader;
   file.read(reinterpret_cast<char*>(&formatSubchunkHeader), 
         sizeof(FormatSubchunkHeader));

   if (toString(formatSubchunkHeader.id, 4) != "fmt ") {
      rLog(channel, "ERROR: %s expecting 'fmt' for subchunk header; got '%s'",
         name.c_str(),
         toString(formatSubchunkHeader.id, 4).c_str());
      return;
   }

   out.write(reinterpret_cast<char*>(&formatSubchunkHeader), 
         sizeof(FormatSubchunkHeader));

   FormatSubchunk formatSubchunk;
   file.read(reinterpret_cast<char*>(&formatSubchunk), sizeof(FormatSubchunk));

   out.write(reinterpret_cast<char*>(&formatSubchunk), sizeof(FormatSubchunk));

   rLog(channel, "format tag: %u", formatSubchunk.formatTag); // show as hex?
   rLog(channel, "samples per second: %u", formatSubchunk.samplesPerSecond);
   rLog(channel, "channels: %u", formatSubchunk.channels);
   rLog(channel, "bits per sample: %u", formatSubchunk.bitsPerSample);

   auto bytes = formatSubchunkHeader.subchunkSize - sizeof(FormatSubchunk);

   auto additionalBytes = new char[bytes];
   file.read(additionalBytes, bytes);
   out.write(additionalBytes, bytes);
   
   FactOrData factOrData;
   file.read(reinterpret_cast<char*>(&factOrData), sizeof(FactOrData));
   out.write(reinterpret_cast<char*>(&factOrData), sizeof(FactOrData));

   if (toString(factOrData.tag, 4) == "fact") {
      FactChunk factChunk;
      file.read(reinterpret_cast<char*>(&factChunk), sizeof(FactChunk));
      out.write(reinterpret_cast<char*>(&factChunk), sizeof(FactChunk));

      file.read(reinterpret_cast<char*>(&factOrData), sizeof(FactOrData));
      out.write(reinterpret_cast<char*>(&factOrData), sizeof(FactOrData));

      rLog(channel, "samples per channel: %u", factChunk.samplesPerChannel);
   }

   if (toString(factOrData.tag, 4) != "data") {
      std::string tag{toString(factOrData.tag, 4)};
      rLog(channel, "%s ERROR: unknown tag>%s<", name.c_str(), tag.c_str());
      return;
   }

   DataChunk dataChunk;
   file.read(reinterpret_cast<char*>(&dataChunk), sizeof(DataChunk));

   rLog(channel, "riff header size = %u" , sizeof(RiffHeader));
   rLog(channel, "subchunk header size = %u", sizeof(FormatSubchunkHeader));
   rLog(channel, "subchunk size = %u", formatSubchunkHeader.subchunkSize);
   rLog(channel, "data length = %u", dataChunk.length);
   
   // TODO if odd there is a padding byte!
   auto data = new char[dataChunk.length];
   file.read(data, dataChunk.length);
   file.close();

   // all of it
//   out.write(data, dataChunk.length);
   // TODO: multiple channels
   uint32_t secondsDesired{10};
   if (formatSubchunk.bitsPerSample == 0) formatSubchunk.bitsPerSample = 8;
   uint32_t bytesPerSample{formatSubchunk.bitsPerSample / uint32_t{8}};
   uint32_t samplesToWrite{secondsDesired * formatSubchunk.samplesPerSecond};
   uint32_t totalSamples{dataChunk.length / bytesPerSample};

   samplesToWrite = std::min(samplesToWrite, totalSamples);

   uint32_t totalSeconds{totalSamples / formatSubchunk.samplesPerSecond};
   rLog(channel, "total seconds %u ", totalSeconds);

   dataChunk.length = samplesToWrite * bytesPerSample;
   out.write(reinterpret_cast<char*>(&dataChunk), sizeof(DataChunk));

   uint32_t startingSample{
      totalSeconds >= 10 ? 10 * formatSubchunk.samplesPerSecond : 0};
   writeSamples(out, data, startingSample, samplesToWrite, bytesPerSample);
   rLog(channel, "writing %u samples", samplesToWrite);
   for (auto sample = startingSample; 
        sample < startingSample + samplesToWrite; 
        sample++) {
      auto byteOffsetForSample = sample * bytesPerSample;
      for (uint32_t byte{0}; byte < bytesPerSample; byte++) 
         out.put(data[byteOffsetForSample + byte]);
   }
   rLog(channel, "completed writing %s", name.c_str());
   m_descriptor->add(m_dest, name, 
         totalSeconds, formatSubchunk.samplesPerSecond, formatSubchunk.channels);
   out.close();
}

void WavReader::seekToEndOfHeader(std::ifstream& file, int subchunkSize) {
   auto bytes = subchunkSize - sizeof(FormatSubchunk) + 1;
   file.seekg(bytes, std::ios_base::cur);
}

void WavReader::writeSamples(std::ofstream& out, char* data, 
   uint32_t startingSample, 
   uint32_t samplesToWrite, 
   uint32_t bytesPerSample)
{

}