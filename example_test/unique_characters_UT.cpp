#include "pch.h"
#include "unique_characters.h"

using namespace std;

namespace exercises
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