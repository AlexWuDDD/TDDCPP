#include "StringUtil.h"

std::string StringUtil::head(const std::string& word)
{
    return word.substr(0,1);
}

std::string StringUtil::tail(const std::string& word)
{
    return word.substr(1);
}

std::string StringUtil::zeroPad(const std::string& word, int MaxCodeLength)
{
    auto zerosNeeded = MaxCodeLength - word.length();
    return word + std::string(zerosNeeded, '0');
}

 std::string StringUtil::upperFront(const std::string& string)
 {
    return std::string(1, std::toupper(static_cast<unsigned char>(string.front()))); 
 }