// https://www.geeksforgeeks.org/binary-search/
// could be used on sorted data
// very fast
// start in middle compare if value is less or greater then middle / root if less continue on left if greater continue on right half, continue with same alg.

/*
binarySearch(arr, x, low, high)
	repeat till low = high
		mid = (low + high)/2
			if (x = arr[mid])
				return mid
			else if (x > arr[mid])
				low = mid + 1
			else
				high = mid - 1
*/

// time complexity: O(log N) / recursive O(1)/O(log N)
// space complexity: O(1) / recursive O(1)
 

#pragma once

#include <vector>

class BinarySearch
{
public:
	// static int SearchCLikeArray(const int* arr, int l, int r, int x)
	static int Search(const std::vector<int>& arr, int l, int r, int x)
	{
		while (l <= r) {
			int m = l + (r - l) / 2;
			// Check if x is present at mid
			if (arr[m] == x)
				return m;
			// If x greater, ignore left half
			if (arr[m] < x)
				l = m + 1;
			// If x is smaller, ignore right half
			else
				r = m - 1;
		}
		// if we reach here, then element was not present
		return -1;
	}

	static int RecursiveSearch(const std::vector<int>& arr, int l, int r, int x)
	{
		if (r >= l) 
		{
			int mid = l + (r - l) / 2;

			if (arr[mid] == x)
				return mid;

			if (arr[mid] > x)
				return RecursiveSearch(arr, l, mid - 1, x);

			return RecursiveSearch(arr, mid + 1, r, x);
		}

		// element is not present in array
		return -1;
	}
};