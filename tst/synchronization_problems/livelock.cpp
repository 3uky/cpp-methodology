#include <gtest/gtest.h>

#include <thread>
#include <mutex>
#include <chrono>

namespace synchronization_problems 
{

// a situation where processes/threads are actively working but are not progressing because they are constantly avoiding or reacting to each other.
TEST(SynchronizationProblemsTest, TestLivelock) 
{
    GTEST_SKIP();

    std::mutex mtx1;
    std::mutex mtx2;

    auto thread1 = [&]() {
        while (true)
        {
            if (mtx1.try_lock())
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                if (mtx2.try_lock())
                {
                    mtx2.unlock();
                    mtx1.unlock();
                    break;
                } 
                else
                {
                    mtx1.unlock();
                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
                }
            }
        }
    };

    auto thread2 = [&]() {
        while (true)
        {
            if (mtx2.try_lock())
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                if (mtx1.try_lock())
                {
                    mtx1.unlock();
                    mtx2.unlock();
                    break; // Úspěšné dokončení
                } 
                else
                {
                    mtx2.unlock();
                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
                }
            }
        }
    };

    std::thread t1(thread1);
    std::thread t2(thread2);

    // if test run more then 2 seconds and threads are still running we can assume that livelock occure
    auto start_time = std::chrono::steady_clock::now();
    while (std::chrono::steady_clock::now() - start_time < std::chrono::seconds(2))
    {
        if (t1.joinable() && t2.joinable())
            break;
    }
    ASSERT_FALSE(t1.joinable() && t2.joinable());
}

}