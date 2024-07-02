#include <gtest/gtest.h>
#include "Soundex.h"


TEST(SoundexTest, HandlesEmptyString) {
    std::string actualValue = std::string();
    std::string expectedValue = std::string();
    ASSERT_EQ(generateSoundex(actualValue), expectedValue);
}

TEST(SoundexTest, HandlesSingleCharacter) {
    std::string value = generateSoundex(std::string s("A"));
    std::string expectedValue = std::string("A000");
    ASSERT_EQ(value, expectedValue);
}

