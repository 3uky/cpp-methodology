#pragma once

// https://www.geeksforgeeks.org/quick-sort/
// QuickSort is a sorting algorithm based on the Divide and Conquer algorithm that picks an element as a pivot and partitions the given array around the picked pivot by placing the pivot in its correct position in the sorted array.

// Time Complexity : O(N*logN)/O(N2)
// Space Complexity : O(1) as no extra space is used

#include <vector>

using namespace std;

namespace algorithms
{

class QuickSort
{
public:
    // The main function that implements QuickSort
    // arr[] --> Array to be sorted,
    // low --> Starting index,
    // high --> Ending index
    static void Sort(std::vector<int>& arr, int low, int high)
    {
        if (low < high)
        {

            // pi is partitioning index, arr[p]
            // is now at right place
            int pi = Partition(arr, low, high);

            Sort(arr, low, pi - 1); // separately sort elements left from pivot
            Sort(arr, pi + 1, high); // separately sort elements right from pivot
        }
    }

private:
// This function takes last element as pivot,
// places the pivot element at its correct position
// in sorted array, and places all smaller to left
// of pivot and all greater elements to right of pivot
    static int Partition(std::vector<int>& arr, int low, int high)
    {
        // Choosing the pivot - there could be more strategy e.g. higher index
        const int pivot = arr[high];

        // i: Index of smaller element and indicates the correct position of pivot found so far
        int i = low;

        for (int j = low; j < high; j++)
        {
            // If current element is smaller than the pivot
            if (arr[j] < pivot) 
            {
                swap(arr[i], arr[j]);
                i++; // Increment index of smaller element
            }
        }
        swap(arr[i], arr[high]); // move pivot on place right from elements with lower values
        return i;
    }
};

}