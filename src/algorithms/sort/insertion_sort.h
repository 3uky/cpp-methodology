#pragma once

#include <algorithm>
#include <vector>

// https://builtin.com/machine-learning/fastest-sorting-algorithm
// time complexity: O(n^2)/O(n) worst/best
// space complexity: O(1)

// In this sorting algorithm, we check to see if the order is correct for each element until we reach the current element.
// Since the first element is in order, we start from the second element and check if the order is maintained. 
// If not, then we swap them. So, on any given element, we check if the current element is greater than the previous element.
// If its not, we keep swapping elements until our current element is greater than the previous element.

namespace algorithms
{

class InsertionSort
{
public:
    static void Sort(std::vector<int>& arr)
    {
        for (int i = 1; i < arr.size(); i++)
        {
            for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
            {
                std::swap(arr[j - 1], arr[j]);
            }
        }
    }
};

}


