#include "gmock/gmock.h"

#include "ConditionVariable.h"

#include <array>

using namespace std;

namespace parallel_programming
{

TEST(ConditionVariableTest, ShouldThreadsWaitOnConditionVariableBeforeIncremenCounter)
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


TEST(ConditionVariableTest, WaitAndNotify) {
    std::mutex mtx;
    std::condition_variable cv;
    bool ready = false;

    // thread that waits for the signal
    std::thread waiter([&]() {
        std::unique_lock<std::mutex> lock(mtx);
        while (!ready) {
            cv.wait(lock);  // wait until notification from notifier (unique lock is released during wait and lock again after notification)
        }
        ASSERT_TRUE(ready);
    });

    // thread that signals the other thread
    std::thread notifier([&]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));  // simulate work
        {
            std::lock_guard<std::mutex> lock(mtx);
            ready = true;
        }
        cv.notify_one();  // notify waiting thread
    });

    waiter.join();
    notifier.join();
}

}