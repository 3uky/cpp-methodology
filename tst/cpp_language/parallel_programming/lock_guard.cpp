#include "gmock/gmock.h"

#include <chrono>

using namespace std;

using testing::ContainsRegex;
using testing::MatchesRegex;

namespace parallel_programming
{

TEST(MutexTest, ProtectCriticalSectionWithMutex)
{
    // GIVEN
    std::mutex mtx;

    // critical section (exclusive access to std::cout signaled by locking mtx):
	auto PrintBlockWithMutex = [&](int n, char c) {
        mtx.lock();
        for (int i = 0; i < n; ++i)
	        cout << c;
        mtx.unlock();
    };

    thread th1(PrintBlockWithMutex, 5000, 'A');
    thread th2(PrintBlockWithMutex, 5000, 'B');

    // WHEN
    testing::internal::CaptureStdout();
    th1.join();
    th2.join();

    // THEN
    ASSERT_THAT(::testing::internal::GetCapturedStdout(), MatchesRegex("A*B*"));
}

TEST(MutexTest, ProtectCriticalSectionWithLockGuard)
{
    // GIVEN
    std::mutex mtx;

    // critical section (exclusive access to std::cout signaled by locking mtx):
    auto PrintBlockWithGuard = [&](int n, char c) {
        lock_guard<std::mutex> lck(mtx);

        for (int i = 0; i < n; ++i) {
            cout << c;
        }
    };
    
    // WHEN
    thread th1(PrintBlockWithGuard, 5000, 'A');
    thread th2(PrintBlockWithGuard, 5000, 'B');
    
    testing::internal::CaptureStdout();
    th1.join();
    th2.join();

    // THEN
    ASSERT_THAT(::testing::internal::GetCapturedStdout(), MatchesRegex("A*B*"));
}

TEST(MutexTest, ProtectCriticalSectionWithLockGuardWithLotOfThreads) 
{
    // GIVEN
    std::mutex mtx;
    std::vector<std::thread> threads;
    int shared_data = 0;
    int no_threads = 1000;

    // without protection of critical section race condition could occure
    // race condition scenario: thread A read value of shared_data before increment and it's interupted with thread B
    auto increment = [&]() {
        std::lock_guard<std::mutex> lock(mtx);
        shared_data++;
    };

    // WHEN
    for (int i = 0; i < no_threads; ++i) 
        threads.push_back(std::thread(increment));

    for (auto& t : threads)
        t.join();

    // THEN
    ASSERT_EQ(shared_data, no_threads);
}

}