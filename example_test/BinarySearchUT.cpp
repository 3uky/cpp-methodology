#include "pch.h"
#include "BinarySearch.h"

using namespace std;

namespace algorithms
{

TEST(AlgorightmsTest, ShouldFindElementWithBinarySearch)
{
	// GIVEN
	int arr[] = { 2, 3, 4, 10, 40 };
	int x = 10;
	int n = sizeof(arr) / sizeof(arr[0]);

	// WHEN
	int result = BinarySearch(arr, 0, n - 1, x);

	// THEN
	EXPECT_EQ(result, 3);
}

}