#include "gmock/gmock.h"

#include "BubbleSort.h"

#include <array>
#include <algorithm>

// time complexity:   O(n^2) best/worst case
// space complexity:  O(1)

using namespace std;

namespace algorithms
{

TEST(BubbleSortTest, ShouldSortSequence)
{
	// GIVEN
	std::vector<int> tested_arr = { 10, 7, 8, 9, 1, 5 };

	// make array copy and sort it
	auto sorted_arr = tested_arr;
	sort(std::begin(sorted_arr), std::end(sorted_arr));

	// WHEN
	BubbleSort::Sort(tested_arr);

	// THEN
	EXPECT_EQ(tested_arr, sorted_arr);
}

TEST(BubbleSortTest, ShouldNotSortSortedSequence)
{
	// GIVEN
	std::vector<int> tested_arr = { 10, 7, 8, 9, 1, 5 };
	sort(std::begin(tested_arr), std::end(tested_arr));
	const auto sorted_arr = tested_arr;

	// WHEN
	BubbleSort::Sort(tested_arr);

	// THEN
	EXPECT_EQ(tested_arr, sorted_arr);
}

TEST(BubbleSortTest, ShouldSortSequenceWithRevisedAlgorihm)
{
	// GIVEN
	std::vector<int> tested_arr = { 10, 7, 8, 9, 1, 5 };

	// make array copy and sort it
	auto sorted_arr = tested_arr;
	sort(std::begin(sorted_arr), std::end(sorted_arr));

	// WHEN
	BubbleSort::RevisedSort(tested_arr);

	// THEN
	EXPECT_EQ(tested_arr, sorted_arr);
}

}