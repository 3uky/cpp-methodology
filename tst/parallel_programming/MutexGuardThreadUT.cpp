#include "gmock/gmock.h"

#include "MutexGuardThread.h"

#include <chrono>

using namespace std;

using testing::ContainsRegex;
using testing::MatchesRegex;

namespace parallel_programming
{
    TEST(MutexTest, ShouldAccessCriticalSectionWithMutex)
	{
        // GIVEN
        MyCriticalSection ks;
        thread th1(&MyCriticalSection::PrintBlock, &ks, 5000, 'A');
        thread th2(&MyCriticalSection::PrintBlock, &ks, 5000, 'B');

        // WHEN
        testing::internal::CaptureStdout();
        th1.join();
        th2.join();

    	// THEN
        ASSERT_THAT(::testing::internal::GetCapturedStdout(), MatchesRegex("A*B*A*"));
    }

    TEST(MutexTest, ShouldAccessCriticailSectionWithGuard)
    {
        // GIVEN
        MyCriticalSection ks;
        thread th1(&MyCriticalSection::PrintBlockWithGuard, &ks, 5000, 'A');
        thread th2(&MyCriticalSection::PrintBlockWithGuard, &ks, 5000, 'B');

        // WHEN
        testing::internal::CaptureStdout();
        th1.join();
        th2.join();

        // THEN
        ASSERT_THAT(::testing::internal::GetCapturedStdout(), MatchesRegex("A*B*A*"));
    }
    
    TEST(MutexTest, ShouldThreadsExecuteAtLeastPauseDuration)
    {
        GTEST_SKIP();

        // GIVEN
        MyCriticalSection ks;
        int pause_duration_s = 1;
    	thread t1(&MyCriticalSection::PauseThread, &ks, pause_duration_s);
        thread t2(&MyCriticalSection::PauseThread, &ks, pause_duration_s);
        thread t3(&MyCriticalSection::PauseThread, &ks, pause_duration_s);

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

    TEST(MutexTest, MutexLocking) 
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