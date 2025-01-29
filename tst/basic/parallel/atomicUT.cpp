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

TEST(AtomicTest, NonAtomicIncrement)
{
    GTEST_SKIP();

    // GIVEN
    int non_atomic_value = 0;

    auto increment = [&]() {
        for (int i = 0; i < 1000000; ++i) {
            non_atomic_value++;
        }
    };

    // WHEN
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    // THEN
    ASSERT_NE(non_atomic_value, 2000000); // this is hard to simulate on fast pc
}

}