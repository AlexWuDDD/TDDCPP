#ifndef WAVDESCRIPTOR_H
#define WAVDESCRIPTOR_H

#include <string>
#include <cstdint>
#include <cstring>
#include <fstream>

struct WavDescriptorRecord
{
    int8_t filename[64];
    uint32_t seconds;
    uint32_t samplesPerSecond;
    uint16_t channels;
};

class WavDescriptor
{
public:
    WavDescriptor(const std::string& dir)
    {
        outstr = new std::ofstream(dir + "/WavSnippets.dat", std::ios::out|std::ios::binary);
    }

    void add(const std::string& dir, const std::string& filename, uint32_t totalSeconds,
        uint32_t samplesPerSecond, uint16_t channels)
    {
        WavDescriptorRecord record;
        cpy(record.filename, filename.c_str());
        record.seconds = totalSeconds;
        record.samplesPerSecond = samplesPerSecond;
        record.channels = channels;

        outstr->write(reinterpret_cast<char*>(&record), sizeof(WavDescriptorRecord));
    }

    void cpy(int8_t* dst, const char* src)
    {
        for(int i = 0; src[i] != 0; ++i){
            dst[i] = src[i];
        }
    }

    ~WavDescriptor()
    {
        outstr->close();
        delete outstr;
    }
private:
    std::ofstream* outstr;
};




#endif