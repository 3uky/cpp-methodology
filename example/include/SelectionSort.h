#pragma once

#include <algorithm>

// https://builtin.com/machine-learning/fastest-sorting-algorithm
// time complexity: O(n^2) worst/best
// space complexity: O(1)

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
