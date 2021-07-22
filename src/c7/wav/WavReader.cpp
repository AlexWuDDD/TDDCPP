#include "WavReader.h"
#include "WavDescriptor.h"

#include <iostream>
#include <cstring>
#include <cstdint>
#include <algorithm>

#include "boost/filesystem.hpp"
#include "Eventlog.h"

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

   LOG_INFO("reading from %s writing to %s", source.c_str(), dest.c_str());
}

WavReader::~WavReader()
{
    delete m_descriptor;
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
   LOG_INFO("opening %s", name.c_str());

   std::ifstream file{name, std::ios::in | std::ios::binary};
   if (!file.is_open()) {
      LOG_ERROR("unable to read %s", name.c_str());
      return;
   }

   std::ofstream out{m_dest + "/" + name, std::ios::out | std::ios::binary};

   RiffHeader header;
   file.read(reinterpret_cast<char*>(&header), sizeof(RiffHeader));

   if (toString(header.id, 4) != "RIFF") {
      LOG_ERROR("ERROR: %s is not a RIFF file",
         name.c_str());
      return;
   }
   if (toString(header.format, 4) != "WAVE") {
      LOG_ERROR("ERROR: %s is not a wav file: %s",
         name.c_str(),
         toString(header.format, 4).c_str());
      return;
   }
   out.write(reinterpret_cast<char*>(&header), sizeof(RiffHeader));

   FormatSubchunkHeader formatSubchunkHeader;
   file.read(reinterpret_cast<char*>(&formatSubchunkHeader), 
         sizeof(FormatSubchunkHeader));

   if (toString(formatSubchunkHeader.id, 4) != "fmt ") {
      LOG_ERROR("ERROR: %s expecting 'fmt' for subchunk header; got '%s'",
         name.c_str(),
         toString(formatSubchunkHeader.id, 4).c_str());
      return;
   }

   out.write(reinterpret_cast<char*>(&formatSubchunkHeader), 
         sizeof(FormatSubchunkHeader));

   FormatSubchunk formatSubchunk;
   file.read(reinterpret_cast<char*>(&formatSubchunk), sizeof(FormatSubchunk));

   out.write(reinterpret_cast<char*>(&formatSubchunk), sizeof(FormatSubchunk));

   LOG_INFO("format tag: %u", formatSubchunk.formatTag); // show as hex?
   LOG_INFO("samples per second: %u", formatSubchunk.samplesPerSecond);
   LOG_INFO("channels: %u", formatSubchunk.channels);
   LOG_INFO("bits per sample: %u", formatSubchunk.bitsPerSample);

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

      LOG_INFO("samples per channel: %u", factChunk.samplesPerChannel);
   }

   if (toString(factOrData.tag, 4) != "data") {
      std::string tag{toString(factOrData.tag, 4)};
      LOG_ERROR("%s ERROR: unknown tag>%s<", name.c_str(), tag.c_str());
      return;
   }

   DataChunk dataChunk;
   file.read(reinterpret_cast<char*>(&dataChunk), sizeof(DataChunk));

   LOG_INFO("riff header size = %u" , sizeof(RiffHeader));
   LOG_INFO("subchunk header size = %u", sizeof(FormatSubchunkHeader));
   LOG_INFO("subchunk size = %u", formatSubchunkHeader.subchunkSize);
   LOG_INFO("data length = %u", dataChunk.length);
   
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
   LOG_INFO("total seconds %u ", totalSeconds);

   dataChunk.length = samplesToWrite * bytesPerSample;
   out.write(reinterpret_cast<char*>(&dataChunk), sizeof(DataChunk));

   uint32_t startingSample{
      totalSeconds >= 10 ? 10 * formatSubchunk.samplesPerSecond : 0};
   writeSamples(&out, data, startingSample, samplesToWrite, bytesPerSample);
   
   LOG_INFO("completed writing %s", name.c_str());
   m_descriptor->add(m_dest, name, 
         totalSeconds, formatSubchunk.samplesPerSecond, formatSubchunk.channels);
   out.close();
}

void WavReader::seekToEndOfHeader(std::ifstream& file, int subchunkSize) {
   auto bytes = subchunkSize - sizeof(FormatSubchunk) + 1;
   file.seekg(bytes, std::ios_base::cur);
}

void WavReader::writeSamples(std::ostream* out, char* data, 
   uint32_t startingSample, 
   uint32_t samplesToWrite, 
   uint32_t bytesPerSample)
{
   LOG_INFO("writing %u samples", samplesToWrite);
   for (auto sample = startingSample; 
        sample < startingSample + samplesToWrite; 
        sample++) {
      auto byteOffsetForSample = sample * bytesPerSample;
      for (uint32_t byte{0}; byte < bytesPerSample; byte++) 
         out->put(data[byteOffsetForSample + byte]);
   }
}