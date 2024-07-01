#include "Soundex.h"
#include <cctype>
#include <map>

char getSoundexCode(char c) {
    c = toupper(c);
    std::map<char,char> charMap = { {'B','1'}, {'F','1'}, {'P','1'}, {'V','1'},
                           {'C','2'}, {'G','2'}, {'J','2'}, {'K','2'}, {'Q','2'}, {'S','2'}, {'X','2'}, {'Z','2'},
                           {'D','3'}, {'T','3'},
                           {'L','4'},
                           {'M','5'}, {'N','5'},
                           {'R','6'},
                           {'A','0'}, {'E','0'}, {'I','0'}, {'O','0'}, {'U','0'}, {'H','0'}, {'W','0'}, {'Y','0'}
                           };
    // return Map consonants to digits
    for (auto charValue : charMap) // Look at each key-value pair
    {
        if (charValue.first == c)
        {
            return charValue.second;
        }
    }
}

std::string checkEmptyString(const std::string& name) {
    if (name.empty()) return "";
}

std::string checkSoundexLength(std::string soundex) {
    while (soundex.length() < 4) {
        soundex += '0';
    }
    return soundex;
}

std::string checkCode(char code, std::string soundex, char prevCode) {
    if (code != '0' && code != prevCode) {
        prevCode = code;
        return soundex += code;   
    }
}

std::string generateSoundex(const std::string& name) {
    
    checkEmptyString(name);
    // save first letter of name to code
    std::string soundex(1, toupper(name[0]));
    char prevCode = getSoundexCode(name[0]);

    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
        char code = getSoundexCode(name[i]);
        checkCode(code, soundex, prevCode);
    }
    checkSoundexLength(soundex);
}
