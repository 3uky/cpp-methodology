#include "pch.h"

using namespace std;

namespace basic_elements
{
TEST(LambdaTest, ShouldReturnSummaryThroughLambda)
{
    // GIVEN
    auto sum = [](int n)->int {
        int s = 0;
        for (int k = 1; k <= n; k++) { s += k; }
        return s;
    };

    // WHEN/THEN
    EXPECT_EQ(sum(7), 28);
}

TEST(LambdaTest, ShouldReturnFactorialThroughLambda)
{
    // GIVEN
    auto fact = [](int n) {
        int f = 1;
        for (int k = 1; k <= n; k++)
            f *= k;
        return f;
    };

    // WHEN/THEN
    EXPECT_EQ(fact(7), 5040);
}

}