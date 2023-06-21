#include "pch.h"
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

}