#include "pch.h"
#include "SelectionSort.h"

#include <array>
#include <algorithm>


using namespace std;

namespace algorithms
{

TEST(SelectionSortTest, ShouldSortSequence)
{
	// GIVEN
	std::vector tested_arr = { 10, 7, 8, 9, 1, 5 };

	// make array copy and sort it
	auto sorted_arr = tested_arr;
	sort(std::begin(sorted_arr), std::end(sorted_arr));

	// WHEN
	SelectionSort::Sort(tested_arr);

	// THEN
	EXPECT_EQ(tested_arr, sorted_arr);
}

}