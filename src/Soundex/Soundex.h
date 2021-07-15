#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <string>
/*
1. Retain the first letter. Drop all other occurrences of a, e, i, o, u, y, h, w.
2. Replace consonants with digits (after the first letter):
• b, f, p, v: 1
• c, g, j, k, q, s, x, z: 2
• d, t : 3
• l: 4
• m, n: 5
• r: 6
3. If two adjacent letters encode to the same number, encode them instead as a single number. 
    Also, do so if two letters with the same number are separated by h or w (but code them twice if separated by a vowel). 
    This rule also applies to the first letter.
4. Stop when you have a letter and three digits. Zero-pad if needed.
*/

class Soundex
{
public:
    static const size_t MaxCodeLength{4};
    
    std::string encode(const std::string& word) const;

    std::string encodedDigit(char letter) const;
private:
    std::string encodedDigits(const std::string& word) const;

    bool isComplete(const std::string& encoding) const;
    std::string lastDigit(const std::string& encoding) const;

    void encodeHead(std::string& encoding, const std::string& word) const;
    void encodeTail(std::string& encoding, const std::string& word) const;
    void encodeLetter(std::string& encoding, char letter, char lastLetter) const;

};

#endif