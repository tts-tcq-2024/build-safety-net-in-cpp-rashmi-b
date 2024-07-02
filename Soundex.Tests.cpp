#include <gtest/gtest.h>
#include "Soundex.h"


TEST(SoundexTest, HandlesEmptyString) {
    std::string actualValue = std::string();
    std::string expectedValue = std::string();
    ASSERT_EQ(generateSoundex(actualValue), expectedValue);
}

TEST(SoundexTest, HandlesSingleCharacter) {
    std::string s = "A";
    std::string value = generateSoundex(s);
    std::string expectedValue = std::string("A000");
    ASSERT_EQ(value, expectedValue);
}

TEST(SoundexTest, HandlesDoubleCharacter) {
    std::string s = "Aaaa";
    std::string value = generateSoundex(s);
    std::string expectedValue = std::string("A000");
    ASSERT_EQ(value, expectedValue);
}

TEST(SoundexTest, HandlesMultipleCharacter) {
    std::string s = "Robert";
    std::string value = generateSoundex(s);
    std::string expectedValue = std::string("R163");
    ASSERT_EQ(value, expectedValue);
}

