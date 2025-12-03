#include "gmock/gmock.h"

#include "merge_sort.h"

#include <array>
#include <algorithm>

using namespace std;

namespace algorithms
{

TEST(MergeSortTest, ShouldSortSequenceWithEvenNumberOfElements)
{
	// GIVEN
	vector<int> tested_arr = { 10, 7, 8, 9, 1, 5 };

	// make array copy and sort it
	auto sorted_arr = tested_arr;
	sort(begin(sorted_arr), end(sorted_arr));

	// WHEN
	MergeSort::Sort(tested_arr);

	// THEN
	EXPECT_EQ(tested_arr, sorted_arr);
}

TEST(MergeSortTest, ShouldSortSequenceWithOddNumberOfElements)
{
	// GIVEN
	vector<int> tested_arr = { 10, 7, 8, 9, 1 };

	// make array copy and sort it
	auto sorted_arr = tested_arr;
	sort(begin(sorted_arr), end(sorted_arr));

	// WHEN
	MergeSort::Sort(tested_arr);

	// THEN
	EXPECT_EQ(tested_arr, sorted_arr);
}

}