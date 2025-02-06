#include "gmock/gmock.h"

#include <mutex>
#include <thread>
#include <atomic>

namespace parallel_programming
{

TEST(UniqueLockTest, TestDefaultLockOnInitialization) 
{
    std::mutex mtx;
    std::atomic<int> counter(0);

    auto incrementCounter = [&]() {
        std::unique_lock<std::mutex> lock(mtx);  // locking the mutex
        ++counter;
        // mutex is automatically unlocked when lock goes out of scope
    };
   
    std::thread t1(incrementCounter);
    std::thread t2(incrementCounter);
    std::thread t3(incrementCounter);
    
    t1.join();
    t2.join();
    t3.join();
    
    EXPECT_EQ(counter.load(), 3);
}

TEST(UniqueLockTest, UniqueLockDeferLock) 
{
    std::mutex mtx;
    std::atomic<int> counter(0); // shared resource
    
    auto incrementCounterWithDeferLock = [&]() {
        std::unique_lock<std::mutex> lock(mtx, std::defer_lock); // no lock initially
        std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate other work
    
        lock.lock();
        ++counter;
        lock.unlock();
    };

    std::thread t1(incrementCounterWithDeferLock);
    std::thread t2(incrementCounterWithDeferLock);
    std::thread t3(incrementCounterWithDeferLock);
    
    t1.join();
    t2.join();
    t3.join();
    
    EXPECT_EQ(counter.load(), 3);
}

}