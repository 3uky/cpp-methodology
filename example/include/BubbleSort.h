#pragma once

// https://builtin.com/machine-learning/fastest-sorting-algorithm
// time complexity: O(n^2) worst/best
// space complexity: O(1)

#include <algorithm>
#include <vector>

namespace algorithms
{

class BubbleSort
{
public:
    static void Sort(std::vector<int>& arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 1; j < arr.size(); j++)
            {
                if (arr[j - 1] > arr[j])
                {
                    std::swap(arr[j - 1], arr[j]);
                }
            }
        }
    }

    static void RevisedSort(std::vector<int>& arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            bool isSwapped = false;
            for (int j = 0; j < arr.size() - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    std::swap(arr[j], arr[j + 1]);
                    isSwapped = true;
                }
            }
            if (!isSwapped)
                break;
        }
    }
};

}
