#include <gtest/gtest.h>

#include <thread>
#include <atomic>

namespace parallel_programming 
{

std::atomic<int> counter(0);

void increment() 
{
    for (int i = 0; i < 100000; ++i)
        counter++;
}

// Without proper synchronization an incorrect result of counter is expected.
// The expected result (200000) is unlikely due to the race condition.
TEST(RaceConditionTest, TestRaceCondition) 
{
    std::thread t1(increment);
    std::thread t2(increment);
    
    t1.join();
    t2.join();
    
    ASSERT_NE(counter, 200000);
}

}