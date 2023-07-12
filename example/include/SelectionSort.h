#pragma once

#include <algorithm>
#include <vector>

// https://builtin.com/machine-learning/fastest-sorting-algorithm
// time complexity: O(n^2) worst/best
// space complexity: O(1)

// In this sorting algorithm, we assume that the first element is the minimum element.
// Then we check to see if an element lower than the assumed minimum is present in the rest of the array.
// If there is, we swap the assumed minimum and the actual minimum. Otherwise, we move on to the next element.

namespace algorithms
{

class SelectionSort
{
public:
    static void Sort(std::vector<int>& arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            int minIndex = i;
            for (int j = i + 1; j < arr.size(); j++)
            {
                if (arr[j] < arr[minIndex])
                {
                    minIndex = j;
                }
            }
            std::swap(arr[i], arr[minIndex]);
        }
    }
};

}


#pragma once
