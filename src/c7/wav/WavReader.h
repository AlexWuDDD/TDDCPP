#ifndef WAVREADER_H
#define WAVREADER_H

#include <string>
#include <fstream>
#include "boost/filesystem.hpp"

#include "WavDescriptor.h"

bool hasExtension(const std::string& filename, const std::string& substring);

class WavReader
{
public:
    WavReader(const std::string& source, const std::string& dest);
    virtual ~WavReader();
    void open(const std::string& name, bool trace);
    void list(
        const boost::filesystem::path& dir,
        const std::string& filename,
        std::vector<boost::filesystem::path>& found) const;
    void listAll() const;
    void publishSnippets();
private:
    WavDescriptor* m_descriptor;

    void seekToEndOfHeader(std::ifstream& file, int headerLength);
    std::string toString(int8_t* c, unsigned int size);

    std::string m_source;
    std::string m_dest;

public:
    void writeSamples(std::ostream* out, char* data, 
        uint32_t startingSample,
        uint32_t samplesToWrite,
        uint32_t bytesPerSample);
};
#endif