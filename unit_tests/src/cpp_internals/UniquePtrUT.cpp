#include "pch.h"
#include "UniquePtr.h"

using namespace std;

namespace cpp_internals
{
	TEST(UniquePointerTest, ShouldInitializeThroughParametrizedConstructor)
	{
		// GIVEN
		constexpr int expected_value = 1;

		// WHEN - parametrized constructor (template typename is deducted from value type)
		MyUniquePtr implemented_ptr(expected_value);
		
		// THEN
		EXPECT_EQ(*implemented_ptr, expected_value);
	}

	TEST(UniquePointerTest, ShouldInitializeThroughParametrizedConstructor2)
	{
		// GIVEN
		constexpr int expected_value = 1;

		// WHEN - param. ctor (move ctor is not used probably because compiler optimization)
		MyUniquePtr<int> implemented_ptr = MyUniquePtr(expected_value); 

		// THEN
		EXPECT_EQ(*implemented_ptr, expected_value);
	}

	TEST(UniquePointerTest, ShouldInitializedThroughMoveConstructor2)
	{
		// GIVEN
		constexpr int expected_value = 1;

		// WHEN - move constructor
		MyUniquePtr dyingObject(expected_value);
		MyUniquePtr<int> implemented_ptr = std::move(dyingObject);

		// THEN
		EXPECT_EQ(*implemented_ptr, expected_value);
	}

	TEST(UniquePointerTest, ShouldInitializedThroughMoveAssignment)
	{
		// GIVEN
		constexpr int expected_value = 1;
		MyUniquePtr<int> implemented_ptr_1(expected_value);
		MyUniquePtr<int> implemented_ptr_2;

		// WHEN - move assignment
		implemented_ptr_2 = std::move(implemented_ptr_1);

		// THEN
		EXPECT_EQ(*implemented_ptr_2, expected_value);
	}

	/*
	TEST(UniquePointerTest, UnsupportedOperations)
	{
		MyUniquePtr<int> a, b;

		b = a; // prohibited: copy assignment is deleted

		MyUniquePtr<int> c = b; // prohibited: copy constructor is deleted
	}
	*/
}
