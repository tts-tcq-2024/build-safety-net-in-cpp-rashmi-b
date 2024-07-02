#include <gtest/gtest.h>
#include "Soundex.h"


TEST(SoundexTest, HandlesEmptyString) {
    ASSERT_EQ(generateSoundex(""), "");
}

TEST(SoundexTest, HandlesSingleCharacter) {
    EXPECT_EQ(generateSoundex("A"), "A000");
}

