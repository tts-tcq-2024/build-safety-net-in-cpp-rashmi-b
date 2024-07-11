#include "Soundex.h"
#include <cctype>
#include <map>
#include <numeric>

//Declare and define Map here globally
std::map<char,char> charMap = { {'B','1'}, {'F','1'}, {'P','1'}, {'V','1'},
                        {'C','2'}, {'G','2'}, {'J','2'}, {'K','2'}, {'Q','2'}, {'S','2'}, {'X','2'}, {'Z','2'},
                        {'D','3'}, {'T','3'},
                        {'L','4'},
                        {'M','5'}, {'N','5'},
                        {'R','6'},
                        {'A','0'}, {'E','0'}, {'I','0'}, {'O','0'}, {'U','0'}, {'H','0'}, {'W','0'}, {'Y','0'}
                        };

char getSoundexCode(char c) {
    c = toupper(c);
    auto it = charMap.find(c);
    // return Map consonants to digits
    if (it != charMap.end()) {
        return it->second;
    }
    return '0'; // Default case
}

std::string checkEmptyString(const std::string& name) {
    if (name.empty()){
        return "0000";
    }
}

std::string checkSoundexLength(std::string& soundex) {
    std::string newSoundex = soundex;
    newSoundex.resize(4, '0');
    return std::string(newSoundex);
}

// Function to determine if a character is 'H' or 'W'
bool isCharHW(char c) {
    return c == 'h' || c == 'w';
}

bool checkCode(char code, char prevCode, char c) {
    return (code != '0' && code != prevCode) || isCharHW(c);

}

std::string generateSoundex(const std::string& name) {
    
    // save first letter of name to code
    checkEmptyString(name);

    std::string soundex(1, toupper(name[0]));
    char prevCode = getSoundexCode(name[0]);
    checkSoundexLength(soundex);

    return std::accumulate(name.begin() + 1, name.end(), std::move(soundex),
        [&prevCode](std::string& accumulatedCode, char c) {
            char code = getSoundexCode(c);
            if (checkCode(code, prevCode, c)) {
                accumulatedCode += code;
                prevCode = code;
            }
            return accumulatedCode;
        });

    return checkSoundexLength(soundex);
}
