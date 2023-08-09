#include "pch.h"
#include "BinarySearch.h"

#include <vector>

using namespace std;

namespace algorithms
{

TEST(BinarySearchTest, ShouldFindElement)
{
	// GIVEN
	const vector arr = { 2, 3, 4, 10, 40 };
	constexpr int x = 10;


	// WHEN
	int result = BinarySearch::Search(arr, 0, int(arr.size()) - 1, x);

	// THEN
	EXPECT_EQ(result, 3);
}

TEST(BinarySearchTest, ShouldFindElementWithRecursiveSearch)
{
	// GIVEN
	const vector arr = { 2, 3, 4, 10, 40 };
	constexpr int x = 10;

	// WHEN
	int result = BinarySearch::RecursiveSearch(arr, 0, int(arr.size()) - 1, x);

	// THEN
	EXPECT_EQ(result, 3);
}

}