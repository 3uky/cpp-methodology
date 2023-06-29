#include "pch.h"
#include "UniquePtr.h"

using namespace std;

namespace cpp_internals
{
	TEST(UniquePointerTest, ShouldInitializeThroughParametrizedConstructor)
	{
		// GIVEN
		constexpr int expected_value = 1;

		// WHEN - parametrized constructor
		MyUniquePtr<int> implemented_ptr(new int(expected_value));
		
		// THEN
		EXPECT_EQ(*implemented_ptr, expected_value);
	}

	TEST(UniquePointerTest, ShouldInitializedThroughMoveConstructor)
	{
		// GIVEN
		constexpr int expected_value = 1;

		// WHEN - move  constructor
		MyUniquePtr<int> implemented_ptr = MyUniquePtr<int>(new int(expected_value));

		// THEN
		EXPECT_EQ(*implemented_ptr, expected_value);
	}

	TEST(UniquePointerTest, ShouldInitializedThroughMoveAssignment)
	{
		// GIVEN
		constexpr int expected_value = 1;
		MyUniquePtr<int> implemented_ptr_1 = MyUniquePtr<int>(new int(expected_value));
		MyUniquePtr<int> implemented_ptr_2;

		// WHEN - move assignment
		implemented_ptr_2 = std::move(implemented_ptr_1);

		// THEN
		EXPECT_EQ(*implemented_ptr_2, expected_value);
	}

	TEST(UniquePointerTest, DISABLED_UnsupportedOperations)
	{
		// b = a; // copy assignment is deleted
		// MyUniquePtr<int> c = b; // copy constructor is deleted
	}
}
