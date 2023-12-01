#pragma once

#include "gmock/gmock.h"

#include <span>
#include <array>

namespace basic_elements
{
    int span_func_sum(std::span<const int> data) // since C++20
    {
        int result = 0;
        for (const int e : data)
            result += e;
        return result;
    }

    TEST(SpanTest, ShouldReturnConainerValuesSummary)
    {
        // GIVEN
        std::array<int, 4> container{1, 2, 3, 4};

        // std::span (C++20) is a safer alternative to separated pointer/size.
        int result = span_func_sum({ container.data(), container.size() });

        // THEN
        ASSERT_EQ(result, 10);
    }
}
