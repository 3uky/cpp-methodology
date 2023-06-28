#pragma once

#include "pch.h"

#include "Queue.h"

#include <ranges>

using namespace std;

namespace containers
{

TEST(QueueTest, ShouldReturnFrontElement)
{
    // GIVEN
    unique_ptr<IQueue> q = std::make_unique<Queue>();
    const vector incoming_values{ 1, 2, 3, 4, 5 };

    // WHEN
    for (auto value : incoming_values)
        q->Enqueue(value);

	// THEN
    ASSERT_EQ(q->Peek(), incoming_values.front());

}

TEST(QueueTest, ShouldReturnSize)
{
    // GIVEN
    unique_ptr<IQueue> q = std::make_unique<Queue>();
    const vector incoming_values{ 1, 2, 3, 4, 5 };

	// WHEN
	for (auto value : incoming_values)
        q->Enqueue(value);

	// THEN
    ASSERT_EQ(q->Size(), incoming_values.size());
}

TEST(QueueTest, ShouldNotBeEmptyAfterQueue)
{
    // GIVEN
    unique_ptr<IQueue> q = std::make_unique<Queue>();
    const vector incoming_values{ 1, 2, 3, 4, 5 };

    // WHEN
    for (auto value : incoming_values)
        q->Enqueue(value);

    // THEN
    ASSERT_FALSE(q->IsEmpty());
}

TEST(QueueTest, ShouldBeEmptyAfterDeque)
{
    // GIVEN
    unique_ptr<IQueue> q = std::make_unique<Queue>();
    const vector incoming_values{ 1, 2, 3, 4, 5 };

    // WHEN
    for (auto value : incoming_values)
        q->Enqueue(value);

    for (auto _ : incoming_values)
        q->Dequeue();

    // THEN
    ASSERT_TRUE(q->IsEmpty());
}

TEST(QueueTest, ShouldEnqueuElement)
{
    // GIVEN
    unique_ptr<IQueue> q = std::make_unique<Queue>();
    constexpr int first = 1, second = 2;

    // WHEN
    q->Enqueue(first);
    q->Enqueue(second);

    // THEN
    EXPECT_EQ(q->Peek(), first);
}

TEST(QueueTest, ShouldDequeuElement)
{
    // GIVEN
    unique_ptr<IQueue> q = std::make_unique<Queue>();
    constexpr int first = 1, second = 2;
    q->Enqueue(first);
    q->Enqueue(second);

    // WHEN
    q->Dequeue();

    // THEN
    EXPECT_EQ(q->Peek(), second);
}
    
}