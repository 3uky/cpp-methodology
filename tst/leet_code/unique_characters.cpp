#include "gmock/gmock.h"

#include "unique_characters.h"

namespace leet_code
{
    TEST(UniqueCharactersTest, ShouldReturnStringWithUniqueCharacters)
    {
        // GIVEN
        std::string string_with_duplicities = "Hello, World!";

    	// WHEN
        const auto result = UniqueCharacters::GetStringWithUniqueCharacters(string_with_duplicities);

        // THEN
        EXPECT_EQ(result, "Helo, Wrd!");
    }
}