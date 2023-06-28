#pragma once

#include "pch.h"

#include "Stack.h"

#include <ranges>

namespace basic_elements
{
TEST(StackTest, ShouldBeEmptyAfterPopAllElements)
{
    // GIVEN
    StackFromVector stack;
    constexpr int first_value = 1, last_value = 5;
    for (const auto value : std::views::iota(first_value, last_value))
        stack.Push(value);

    // WHEN
	for (int i=0; i < last_value - first_value + 1; i++)
		stack.Pop();

    // THEN
    EXPECT_TRUE(stack.Empty());
}

TEST(StackTest, ShouldHaveLastPushedElementOnTop)
{
    // GIVEN
    StackFromVector stack;
    constexpr int first_value = 1, last_value = 5;

    // WHEN
	for (const auto value : std::views::iota(first_value, last_value + 1))
        stack.Push(value);

    // THEN
    EXPECT_EQ(stack.Top(), last_value);    
}

TEST(StackTest, ShouldPopLastPushedElement)
{
    // GIVEN
    StackFromVector stack;
    constexpr int first_value = 1, last_value = 5;
    for(const auto value : std::views::iota(first_value, last_value + 1))
		stack.Push(value);

    // WHEN
    stack.Pop();

    // THEN
	EXPECT_EQ(stack.Top(), last_value - 1);
}

}