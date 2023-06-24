#include "pch.h"
#include "ConditionVariable.h"

#include <array>

using namespace std;


namespace parallel_programming
{

TEST(ParalellProgrammingTest, ShouldThreadsWaitOnConditionVariableBeforeIncremenCounter)
{
    // GIVEN
    constexpr int numberOfThreads = 10;
    std::array<std::thread, numberOfThreads> threads;
    MyConditionVariable myConditionVariable;

    /// WHEN
    for (auto& thread : threads) // spawn 10 threads
        thread = std::thread(&MyConditionVariable::IncrementCounter, &myConditionVariable);

    // THEN
    EXPECT_EQ(myConditionVariable.GetCounter(), 0);

    // WHEN
    myConditionVariable.Go();
    for (auto& thread : threads)
        thread.join();

    // THEN
    EXPECT_EQ(myConditionVariable.GetCounter(), numberOfThreads);
}

}