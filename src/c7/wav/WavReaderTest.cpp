#include "gtest/gtest.h"
#include "WavReader.h"
#include <iostream>
#include <string>
#include <sstream>
#include "Eventlog.h"

using namespace std;
class WavReaderTest : public ::testing::Test {
public:
    WavReader reader{".","."};
    ostringstream out;
};

TEST_F(WavReaderTest, WritesSingleSample) 
{ 
    char data[] = "abcd";
    uint32_t bytesPerSample { 1 };
    uint32_t startingSample { 0 };
    uint32_t samplesToWrite { 1 };
    reader.writeSamples(&out, data, startingSample, samplesToWrite, bytesPerSample); 
    EXPECT_EQ("a", out.str());
}
