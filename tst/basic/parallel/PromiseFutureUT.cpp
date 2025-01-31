#include <gtest/gtest.h>

#include <future>
#include <thread>

namespace parallel_programming
{

TEST(PromiseFutureTest, TwoThreadsCommunication) {
    std::promise<int> promise;
    std::future<int> future = promise.get_future();

    auto producer = [&]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));  // simulate work
        promise.set_value(42);
    };

    auto consumer = [&]() {
        int value = future.get();  // block until the value is set in the promise
        ASSERT_EQ(value, 42);
    };

    std::thread producer_thread(producer);
    std::thread consumer_thread(consumer);

    producer_thread.join();
    consumer_thread.join();
}

}