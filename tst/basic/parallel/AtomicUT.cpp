#include <gtest/gtest.h>

#include <atomic>
#include <thread>

namespace parallel_programming
{

TEST(AtomicTest, AtomicIncrement)
{
    std::atomic<int> value = 0;

    // Launch multiple threads to increment the atomic variable
    auto increment = [&]() {
        for (int i = 0; i < 1000; ++i) {
            value.fetch_add(1, std::memory_order_relaxed);  // Atomic increment           
        }
    };

    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    ASSERT_EQ(value.load(std::memory_order_relaxed), 2000);
}

// test depends on cpu, if is fast enough race condition won't occur and test would fail
TEST(AtomicTest, NonAtomicIncrement)
{
    //GTEST_SKIP();

    // GIVEN
    int non_atomic_value = 0;

    // if two threads read the same value of counter at the same time,
    // they both increment it and write back the same new value, causing a lost update
    auto increment = [&]() {
        for (int i = 0; i < 10000; ++i) {
            int temp = non_atomic_value;  // read the current value
            temp++;                       // increment the local copy
            non_atomic_value = temp;  

        }
    };

    // WHEN
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    // THEN
    ASSERT_NE(non_atomic_value, 20000); // there would be lower value then expected if race condtion occur
}

}