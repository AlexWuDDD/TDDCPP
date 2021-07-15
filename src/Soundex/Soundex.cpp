#include "Soundex.h"
#include <unordered_map>
#include "../utilities/StringUtil.h"
#include "../utilities/CharUtil.h"

static const std::string NotADigit{"*"};


std::string Soundex::encode(const std::string& word) const
{
    return StringUtil::zeroPad(StringUtil::upperFront(StringUtil::head(word)) + StringUtil::tail(encodedDigits(word)), MaxCodeLength);
}

std::string Soundex::encodedDigits(const std::string& word) const
{
    std::string encoding;
    encodeHead(encoding, word);
    encodeTail(encoding, word);
    return encoding;
}

std::string Soundex::encodedDigit(char letter) const
{
    const std::unordered_map<char, std::string> encodings{
        {'b', "1"},{'f', "1"},{'p', "1"},{'v', "1"},
        {'c', "2"},{'g', "2"},{'j', "2"},{'k', "2"}, {'q', "2"},
                   {'s', "2"},{'x', "2"},{'z', "2"},
        {'d', "3"},{'t', "3"},
        {'l', "4"},
        {'m', "5"},{'n', "5"},
        {'r', "6"}
    };
    auto it = encodings.find(CharUtil::lower(letter));
    return it == encodings.end() ? NotADigit : it->second;
}

 bool Soundex::isComplete(const std::string& encoding) const
 {
    return encoding.length() == MaxCodeLength;
 }

std::string Soundex::lastDigit(const std::string& encoding) const
{
    if(encoding.empty()) return NotADigit;
    return std::string(1, encoding.back());
}

void Soundex::encodeHead(std::string& encoding, const std::string& word) const
{
    encoding += encodedDigit(word.front());
}

void Soundex::encodeTail(std::string& encoding, const std::string& word) const
{
    for(auto i = 1u; i < word.length(); ++i){
        if(!isComplete(encoding)){
            encodeLetter(encoding, word[i], word[i-1]);
        }
    }
}

void Soundex::encodeLetter(std::string& encoding, char letter, char lastLetter) const
{
    auto digit = encodedDigit(letter);
    if(digit != NotADigit && (digit != lastDigit(encoding) || CharUtil::isVowel(lastLetter))){
        encoding += digit;
    }
}