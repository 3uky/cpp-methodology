#pragma once

#include "pch.h"

#include <algorithm>
#include <array>

namespace basic_elements
{
	// predicates
	bool divides_4(int x) { return x % 4 == 0; };
	bool divides_13(int x) { return x % 13 == 0; };
	//auto divides_13 = [](int x) { return x % 13 == 0; };

	TEST(FindTest, ShouldFindElementByPredicate)
	{
		// GIVEN
		const std::array<int, 4> sequence = { 1, 4, 3, 2 };

		// WHEN
		auto result = std::ranges::find_if(sequence, divides_4);
				
		// THEN			
		EXPECT_EQ(*result, sequence.at(1));
	}

	TEST(FindTest, ShouldFindElementByValue)
	{
		// GIVEN
		const std::array<int, 4> sequence = { 1, 4, 3, 2 };

		// WHEN
		auto result = std::ranges::find(sequence, 4);

		// THEN			
		EXPECT_EQ(*result, sequence.at(1));
	}

	TEST(FindTest, ShouldNotFindElementByPredicate1)
	{
		// GIVEN
		const std::array<int, 4> sequence = { 1, 4, 3, 2 };

		// WHEN
		auto result = std::ranges::find_if(sequence, divides_13);

		// THEN			
		EXPECT_EQ(result, sequence.end());
	}

	TEST(FindTest, ShouldNotFindElementByPredicate2)
	{
		// GIVEN
		const std::array<int, 4> sequence = { 1, 4, 3, 2 };

		// WHEN
		auto result = std::ranges::find_if_not(sequence, divides_13);

		// THEN			
		EXPECT_EQ(result, sequence.begin());
	}


}