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

std::string checkSoundexLength(const std::string& soundex) {
    std::string paddedSoundex = soundex;
    paddedSoundex.resize(4, '0'); // Pad with '0' if soundex is less than 4 characters
    return paddedSoundex;
}

bool checkCode(char code, char prevCode) {
    return (code != '0' && code != prevCode);

}

void appendCode(std::string& result, char code, char& prevCode, size_t& length) {
    result += (code != '0' && checkCode(code, prevCode)) ? (prevCode = code, code) : '0';
    length++;
}

std::string AccumulateSoundex(const std::string& soundex, const std::string& name, char prevCode) {
    std::string result = soundex.substr(0, 1); // Initialize result with the first character of soundex
    size_t length = 1;

    for (char c : name.substr(1)) {
        if (length >= 4) break; // Exit early if result already has 4 characters

        char code = getSoundexCode(c);
        appendCode(result, code, prevCode, length);
    }

    result.append(4 - result.length(), '0'); // Pad with '0' if result is less than 4 characters
    return result.substr(0, 4); // Ensure the result is exactly 4 characters long
}

std::string generateSoundex(const std::string& name) {
    
    // save first letter of name to code
    checkEmptyString(name);

    std::string soundex(1, toupper(name[0]));
    char prevCode = getSoundexCode(name[0]);

    return AccumulateSoundex(soundex, name, prevCode);
}