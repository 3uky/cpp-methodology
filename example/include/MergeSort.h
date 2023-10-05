#pragma once

#include <vector>

// https://builtin.com/machine-learning/fastest-sorting-algorithm
// time complexity: O(N*logN)
// space complexity: O(N)

namespace algorithms
{
    class MergeSort
    {
    public:
        static void Sort(std::vector<int>& arr)
        {
            Sort(arr.data(), 0, static_cast<int>(arr.size()) - 1);
        }

    private:
        // The below function will recursively break the array into two sub - arrays until each sub - array has only one element.
        static void Sort(int* arr, int l, int r)
        {
            if (l < r) {
                int m = l + (r - l) / 2;
                //int m = (l + r) / 2; // could overflow
                Sort(arr, l, m);
                Sort(arr, m + 1, r);
                Merge(arr, l, m, r);
            }
        }

        // After that, we store these sub-arrays in two new arrays. Now, we can start merging them based on their order,
        // and store them into our input array. After all these sub-arrays are merged, our input array will be sorted.
        static void Merge(int* arr, int l, int m, int r)
    	{
            const int n1 = m - l + 1;
            const int n2 = r - m;
            int* L = new int[n1];
            int* R = new int[n2];

        	for (int i = 0; i < n1; i++)
            {
                L[i] = arr[l + i];
            }
            for (int i = 0; i < n2; i++)
            {
                R[i] = arr[m + 1 + i];
            }

        	int i = 0, j = 0, k = l;
            while (i < n1 && j < n2)
            {
                if (L[i] <= R[j])
                {
                    arr[k++] = L[i++];
                }
                else
                {
                    arr[k++] = R[j++];
                }
            }

        	while (i < n1)
            {
                arr[k++] = L[i++];
            }
            while (j < n2)
            {
                arr[k++] = R[j++];
            }

            delete [] L;
            delete [] R;
        }
    };


    static void MergeVectorVersion(std::vector<int>& arr, int l, int m, int r)
    {
        std::vector<int> L(arr.cbegin() + l, arr.cbegin() + m + 1); // initialization <first, last) last is not included
        std::vector<int> R(arr.cbegin() + m + 1, arr.cbegin() + r + 1);
        const auto n1 = L.size();
        const auto n2 = R.size();

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k++] = L[i++];
            }
            else
            {
                arr[k++] = R[j++];
            }
        }

        while (i < n1)
        {
            arr[k++] = L[i++];
        }
        while (j < n2)
        {
            arr[k++] = R[j++];
        }
    }

}


