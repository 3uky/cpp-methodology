#include "gmock/gmock.h"

#include "Stack.h"

#include <ranges>

namespace containers
{

TEST(StackTest, ShouldBeEmptyAfterPopAllElements)
{
    // GIVEN
    std::unique_ptr<IStack> stack = std::make_unique<Stack>();
    constexpr int first_value = 1, last_value = 5, no_values = last_value - first_value + 1;

    for (const auto value : std::views::iota(first_value, last_value + 1))
        stack->Push(value);

    // WHEN
	for (int i=0; i < no_values; i++)
		stack->Pop();

    // THEN
    EXPECT_TRUE(stack->Empty());
}

TEST(StackTest, ShouldHaveLastPushedElementOnTop)
{
    // GIVEN
    std::unique_ptr<IStack> stack = std::make_unique<Stack>();
    constexpr int first_value = 1, last_value = 5;

    // WHEN
	for (const auto value : std::views::iota(first_value, last_value + 1))
        stack->Push(value);

    // THEN
    EXPECT_EQ(stack->Top(), last_value);    
}

TEST(StackTest, ShouldPopLastPushedElement)
{
    // GIVEN
    std::unique_ptr<IStack> stack = std::make_unique<Stack>();
    constexpr int first_value = 1, last_value = 5;
    for(const auto value : std::views::iota(first_value, last_value + 1))
		stack->Push(value);

    // WHEN
    stack->Pop();

    // THEN
	EXPECT_EQ(stack->Top(), last_value - 1);
}

}