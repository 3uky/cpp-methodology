#include <vector>

int max_sum(std::vector<int>& arr, int k) 
{
    int n = arr.size();
    int max_sum = 0;

    for (int i = 0; i <= n - k; i++) 
    {
        int current_sum = 0;

        for (int j = 0; j < k; j++)
        {
            current_sum += arr[i + j];
        }

        max_sum = std::max(current_sum, max_sum);
    }

    return max_sum;
}