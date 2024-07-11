#include <gtest/gtest.h>
#include "Soundex.h"


TEST(SoundexTest, HandlesEmptyString) {
    std::string actualValue = "";
    std::string expectedValue = "";
    EXPECT_EQ(generateSoundex(actualValue), expectedValue);
}

TEST(SoundexTest, HandlesSingleCharacter) {
    std::string s = "A";
    std::string value = generateSoundex(s);
    std::string expectedValue = std::string("A000");
    EXPECT_EQ(value, expectedValue);
}

TEST(SoundexTest, HandlesDoubleCharacter) {
    std::string s = "AAAA";
    std::string value = generateSoundex(s);
    std::string expectedValue = std::string("A000");
    EXPECT_EQ(value, expectedValue);
}

TEST(SoundexTest, HandlesMultipleCharacter) {
    std::string s = "Robert";
    std::string value = generateSoundex(s);
    std::string expectedValue = std::string("R163");
    EXPECT_EQ(value, expectedValue);
}

TEST(SoundexTest, HandlesNonAlphabeticCharacters) {
    std::string s = "Hew698";
    std::string value = generateSoundex(s);
    std::string expectedValue = std::string("0000");
    EXPECT_EQ(value, expectedValue);
}

TEST(SoundexTest, HandlesAllVowels) {
    std::string s = "aeiou";
    std::string value = generateSoundex(s);
    std::string expectedValue = std::string("A000");
    EXPECT_EQ(value, expectedValue);
}