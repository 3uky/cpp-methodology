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

TEST(SyncrhonizationProblemsTest, TestStarvationSolvedWithConditionVariable)
{
    GTEST_SKIP();

    int no_runs = 1000;
    std::mutex mtx;
    std::condition_variable cv;
    std::atomic<int> counterHighThread(0);
    std::atomic<int> counterLowThread(0);
    std::atomic<int> counterAllThreads(0);
    // a flag to control which thread should acquire the lock next (to ensure fairness)
    // 0 means high-priority thread, 1 means low-priority thread
    std::atomic<int> turn(0);

    auto high_priority_thread= [&]() 
    {
        while (counterAllThreads < no_runs)
        {
            std::unique_lock<std::mutex> lock(mtx);
            // unlock lock during wait (when lambda return true it stops waiting and lock lock)
            cv.wait(lock, [&turn] { return turn == 0; });

            ++counterAllThreads;
            ++counterHighThread;

            turn = 1;
            cv.notify_all();
        }
    };

    // low-priority thread: sleeps to simulate being less active
    auto low_priority_thread = [&]() {
        while (counterAllThreads < no_runs) 
        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [&turn] { return turn == 1; });

            std::this_thread::sleep_for(std::chrono::milliseconds(1));

            ++counterAllThreads;
            ++counterLowThread;

            turn = 0;
            cv.notify_all();
        }
    };

    std::thread t1(high_priority_thread);
    std::thread t2(low_priority_thread);

    t1.join();
    t2.join();

    // the counters should be close to each other since both threads get a fair chance
    ASSERT_NEAR(counterHighThread, no_runs/2, 1);
    ASSERT_NEAR(counterLowThread, no_runs/2, 1);
}

}