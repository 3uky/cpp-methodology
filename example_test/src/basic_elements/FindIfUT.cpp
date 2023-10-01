
#pragma once

#include "pch.h"

#include <algorithm>
#include <array>

namespace basic_elements
{
	// predicates
	auto divides_4 = [](int x) { return x % 4 == 0; };
	auto divides_13 = [](int x) { return x % 13 == 0; };

	TEST(FindIfTest, ShouldFindElementByPredicate)
	{
		// GIVEN
		int v[4] = {4, 1, 3, 2};

		// WHEN
		auto result = std::ranges::find_if(v, divides_4);
			
		
		// THEN			
		//EXPECT_EQ(*result, 4);
		EXPECT_EQ(result, &v[0]);
	}

	TEST(FindIfTest, ShouldNotFindElementByPredicate)
	{
		// GIVEN
		const auto v = { 4, 1, 3, 2 };

		// WHEN
		auto result = std::ranges::find_if(v, divides_13);

		// THEN			
		EXPECT_EQ(result, v.end());
	}
}