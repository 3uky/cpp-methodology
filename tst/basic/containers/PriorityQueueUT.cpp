#include "gmock/gmock.h"

#include <queue>
#include <vector>

using ::testing::UnorderedElementsAre;

namespace exercises
{
    std::vector<int> PriorityQueueToVector(std::priority_queue<int, std::vector<int>, std::greater<int>> queue)
    {
        std::vector<int> result;
        while (!queue.empty())
        {
            result.push_back(queue.top());
            queue.pop();
        }
        return result;
    }
    
    // https://stackoverflow.com/questions/75242757/should-the-underlying-container-of-a-priority-queue-be-considered-a-complete-bin
    template <typename T, typename Container, typename Comp>
    const Container& GetUnderlyingContainer(const std::priority_queue<T, Container, Comp>& queue)
    {
        struct access_t : std::priority_queue<T, Container, Comp>
        {
            auto member_ptr() 
            { 
                return &access_t::c;
            }
        } access;
        
        auto ptr = access.member_ptr();
        return queue.*ptr;
    }

    TEST(PriorityQueueTest, ShouldReturnGreatestValues)
    {
        // GIVEN
        const auto input_data = {1, 2, 3, 13, 16, 4, 5, 6, 7, 8, 9, 10, 11, 22, 33};
        constexpr int max_elements = 5;
        std::priority_queue<int, std::vector<int>, std::greater<int>> myQueue(input_data.begin(), input_data.end());

        // WHEN
        while(myQueue.size() > max_elements)
            myQueue.pop();

        // THEN
        ASSERT_THAT(GetUnderlyingContainer(myQueue), UnorderedElementsAre(11, 13, 16, 22, 33));
    }
}