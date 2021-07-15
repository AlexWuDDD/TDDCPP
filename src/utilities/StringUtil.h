#ifndef STRINGUTIL_H
#define STRINGUTIL_H

#include <string>

class StringUtil
{
public:
    static std::string head(const std::string& word);
    static std::string tail(const std::string& word);
    static std::string zeroPad(const std::string& word, int MaxCodeLength);
    static std::string upperFront(const std::string& string);
private:
    StringUtil() = delete;
    ~StringUtil() = delete;

    StringUtil(const StringUtil& rhs) = delete;
    StringUtil& operator=(const StringUtil& rhs) = delete;
};

#endif