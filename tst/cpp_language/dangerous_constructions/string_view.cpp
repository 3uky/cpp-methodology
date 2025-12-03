// https://devblogs.microsoft.com/cppblog/stdstring_view-the-duct-tape-of-string-types/

#include "gmock/gmock.h"

#include "hash_map.h"

using namespace std;
using ::testing::Ne;

namespace undefined_behavior
{
	// during structure X construction a temporary object is created and passes as argument
	// string view member in structure doesnt own passed memory of temporary object
	// temporary object is destructed after object initialization and memory became unvalid
	// accessing memory through object string view member result in undefined behavior
	TEST(StringViewTest, ShouldAccessUnvalidatedMemory)
	{
		GTEST_SKIP();

		// GIVEN
		std::string hello{"Hello"};
		struct X
		{
			std::string_view sv; // Danger!
			explicit X(std::string_view sv_) : sv(sv_) {}
		};

		// WHEN
		X example{ hello + ", World!" };		
		
		// THEN
		ASSERT_THAT(example.sv[0], Ne('H')); // undefined behavior!
	}


	// user defined literal is converted to temporary string which is destructed on the end of expression
	// string view is pointing to unvalid memory,  access on string view caused undefined behavior
	TEST(StringViewTest, ShouldAccessUnvalidatedMemory2)
	{
		GTEST_SKIP();

		// GIVEN / WHEN
		std::string_view bad("Hello, World!"s);

		// THEN
		ASSERT_THAT(bad[0], Ne('H')); // undefined behavior!
	}

}