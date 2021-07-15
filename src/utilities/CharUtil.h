#ifndef CHARUTIL_H
#define CHARUTIL_H

class CharUtil
{
public:
    static char lower(char c);
    static bool isVowel(char letter);
private:
    CharUtil() = delete;
    ~CharUtil() = delete;
    CharUtil(const CharUtil& rhs) = delete;
    CharUtil& operator=(const CharUtil& rhs)= delete;
};

#endif