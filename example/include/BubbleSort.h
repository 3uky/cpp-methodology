#pragma once

#include <algorithm>
#include <vector>
namespace algorithms
{

class BubbleSort
{
public:
    static void Sort(std::vector<int>& arr)
    {
        int n = static_cast<int>(arr.size());

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    std::swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    static void RevisedSort(std::vector<int>& arr)
    {
        int n = static_cast<int>(arr.size());

        for (int i = 0; i < n; i++)
        {
            bool isSwapped = false;
            for (int j = 0; j < n - 1; j++)
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
