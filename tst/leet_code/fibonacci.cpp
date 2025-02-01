#include "gmock/gmock.h"

#include "fibonacci.h"

using namespace std;
using ::testing::ElementsAre;

namespace exercises
{
    TEST(FibonacciTest, ShouldReturnExpectedSequenceOnZeroLenght)
    {
        // GIVEN
        FibonacciVector fib;

        // WHEN
        const std::vector<int> result = fib.GetSequence(0);

        //THEN
        EXPECT_THAT(result, ElementsAre());
    }

	TEST(FibonacciTest, ShouldReturnExpectedSequenceOnOneLenght)
    {
        // GIVEN
        FibonacciVector fib;

        // WHEN
        const std::vector<int> result = fib.GetSequence(1);

        //THEN
        EXPECT_THAT(result, ElementsAre(0));
    }

    TEST(FibonacciTest, ShouldReturnExpectedSequence)
    {
        // GIVEN
        FibonacciVector fib;

        // WHEN
        const std::vector<int> result = fib.GetSequence(9);

        //THEN
        EXPECT_THAT(result, ElementsAre(0, 1, 1, 2, 3, 5, 8, 13, 21));
    }

    TEST(FibonacciTest, ShouldReturnExpectedNumber)
    {
        // GIVEN
        FibonacciVector fib;

        // WHEN
        const auto result = fib.GetNumber(9);

        //THEN
        EXPECT_EQ(result, 21);
    }

    TEST(FibonacciTest, ShouldReturnSameSequenceWithDifferentImplementations)
    {
        // GIVEN
        FibonacciVector fib;
        Fibonacci fib2;

        // WHEN
        auto result_1 = fib.GetSequence(9);
        auto result_2 = fib2.GetSequence(9);

        //THEN
        EXPECT_EQ(result_1, result_2);
    }
    TEST(FibonacciTest, Test)
    {
        Fibonacci fib;
        EXPECT_EQ(fib.GetNumber(1), 0);
        EXPECT_EQ(fib.GetNumber(2), 1);
        EXPECT_EQ(fib.GetNumber(3), 1);
        EXPECT_EQ(fib.GetNumber(4), 2);
    }
}
