#include <gtest/gtest.h>

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>

namespace parallel_programong
{

// In case of starvation, the low-priority thread will have fewer opportunities to access the resource.
// Therefore, the counter will not reach 2000, because high-priority thread runs more frequently.
TEST(SyncrhonizationProblemsTest, TestStarvation)
{
    std::mutex mtx;
    std::atomic<int> counterHighThread(0);
    std::atomic<int> counterLowThread(0);
    std::atomic<int> counterAllThreads(0);

    auto high_priority_thread = [&]() 
    {
        while (counterAllThreads < 1000)
        {
            mtx.lock();
            ++counterAllThreads;
            ++counterHighThread;
            mtx.unlock();
        }
    };

    auto low_priority_thread = [&]()
    {
        while (counterAllThreads < 1000)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));  // simulate being less active
            mtx.lock();
            ++counterAllThreads;
            ++counterLowThread;
            mtx.unlock();
        }
    };

    std::thread t1(high_priority_thread);
    std::thread t2(low_priority_thread);

    t1.join();
    t2.join();

    ASSERT_LT(counterLowThread, counterHighThread);
}

}