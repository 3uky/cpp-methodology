#include "pch.h"
#include "mutex_guard_thread.h"
#include <chrono>

using namespace std;

using testing::ContainsRegex;
using testing::MatchesRegex;

namespace parallel_programming
{
    TEST(ParalellProgrammingTest, ShouldAccessCriticalSectionWithMutex)
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

    TEST(ParalellProgrammingTest, ShouldAccessCriticailSectionWithGuard)
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
    
    TEST(ParalellProgrammingTest, DISABLED_ShouldThreadsExecuteAtLeastPauseDuration)
    {
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

}