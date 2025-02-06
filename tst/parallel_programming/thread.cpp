#include "gmock/gmock.h"

#include <chrono>

namespace parallel_programming
{

TEST(MutexTest, executeMultipleThreads)
{
    GTEST_SKIP();

    // GIVEN
    int pause_duration_s = 1;
    auto PauseThread = [&](int n) {
        std::this_thread::sleep_for(std::chrono::seconds(n));
        std::cout << "pause of " << n << " seconds ended" << std::endl;
    };

    std::thread t1(PauseThread, pause_duration_s);
    std::thread t2(PauseThread, pause_duration_s);
    std::thread t3(PauseThread, pause_duration_s);

    // WHEN
    auto const start = std::chrono::steady_clock::now();
    t1.join();
    t2.join();
    t3.join();
    auto const end = std::chrono::steady_clock::now();
    const std::chrono::duration<double> elapsed_seconds = end - start;

    // THEN
    EXPECT_GE(elapsed_seconds.count(), pause_duration_s);
}

}