

#include "pch.h"

#include <queue>
#include <vector>
#include <array>

using namespace std;
using ::testing::UnorderedElementsAre;

namespace exercises
{

    std::vector<int> PriorityQueueToVector(std::priority_queue<int, std::vector<int>, std::greater<int>>& queue)
    {
        std::vector<int> result;
        while (!queue.empty())
        {
            result.push_back(queue.top());
            queue.pop();
        }
        return result;
    }

    TEST(PriorityQueueTest, ShouldReturnGreatestValues)
    {
        // GIVEN
        std::vector input_data{1, 2, 3, 13, 16, 4, 5, 6, 7, 8, 9, 10, 11, 22, 33};
        constexpr int max_elements = 5;
        std::priority_queue<int, std::vector<int>, std::greater<int>> myQueue;

        // WHEN
        for(auto value : input_data)
        {
            myQueue.emplace(value);
            if (myQueue.size() > max_elements)
                myQueue.pop();
        }

        // THEN
        ASSERT_THAT(PriorityQueueToVector(myQueue), UnorderedElementsAre(11, 13, 16, 22, 33));
    }
}