#include "gmock/gmock.h"

#include "reverse_string.h"

using namespace std;

namespace exercises
{

TEST(ReverseStringTest, ShouldReverseString)
{
    // GIVEN
    std::string str = "!dlroW ,olleH";

    // WHEN
	UtilString::Reverse(str);

	// THEN
    EXPECT_EQ(str, "Hello, World!");
}


TEST(ReverseStringTest, ShouldReverseCString)
{
    // GIVEN
    char str[14] = "!dlroW ,olleH";

    // WHEN
    UtilString::ReverseC(str);

    // THEN
    EXPECT_EQ(std::string(str), "Hello, World!");
}


}