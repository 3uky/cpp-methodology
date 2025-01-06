#include "gmock/gmock.h"

#include "QuickSort.h"

#include <array>
#include <algorithm>


using namespace std;

namespace algorithms
{
TEST(QuickSortTest, ShouldSortSequence)
{
	// GIVEN
    std::vector<int> tested_arr = { 10, 7, 8, 9, 1, 5 };

	// make array copy and sort it
	auto sorted_arr = tested_arr;
	sort(std::begin(sorted_arr), std::end(sorted_arr));

	// WHEN
    QuickSort::Sort(tested_arr, 0, int(tested_arr.size()) - 1);
	
	// THEN
    EXPECT_EQ(tested_arr, sorted_arr);
}

TEST(QuickSortTest, ShouldNotSortSortedSequence)
{
	// GIVEN
	std::vector<int> tested_arr = { 10, 7, 8, 9, 1, 5 };
	sort(std::begin(tested_arr), std::end(tested_arr));
	const auto sorted_arr = tested_arr;

	// WHEN
	QuickSort::Sort(tested_arr, 0, int(tested_arr.size()) - 1);

	// THEN
	EXPECT_EQ(tested_arr, sorted_arr);
}

}