#include <gtest/gtest.h>

#include <thread>
#include <mutex>
#include <chrono>

namespace synchronization_problems 
{

// a situation where processes/threads are blocking each other and neither can proceed.
TEST(SynchronizationProblemsTest, TestDeadlock) 
{
    GTEST_SKIP();

    std::mutex mtx1;
    std::mutex mtx2;

    auto thread1 = [&]()
    {
        mtx1.lock();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        mtx2.lock();
        mtx2.unlock();
        mtx1.unlock();
    };

    auto thread2 = [&]() 
    {
        mtx2.lock();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        mtx1.lock();
        mtx1.unlock();
        mtx2.unlock();
    };

    std::thread t1(thread1);
    std::thread t2(thread2);

    // daeadlock occure

    t1.join();
    t2.join();
}

}