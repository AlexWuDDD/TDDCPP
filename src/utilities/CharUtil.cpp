#include "CharUtil.h"
#include <string>

char CharUtil::lower(char c)
{
    return std::tolower(static_cast<unsigned char>(c));
}

bool CharUtil::isVowel(char letter)
{
    return std::string("aeiouy").find(lower(letter)) != std::string::npos;
}