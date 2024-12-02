#include "gmock/gmock.h"

#include "Iterator.h"

using ::testing::ElementsAre;

namespace containers
{

TEST(ContainersIteratorTest, ShouldReturnFirstElement)
{
    // GIVEN
    MyContainer<int> container(5);
    for (int i = 0; i < 5; ++i)
        container[i] = i * 10;
    
    // WHEN/THEN
    ASSERT_EQ(*container.begin(), container[0]);
}

TEST(ContainersIteratorTest, ShouldReturnLastElement)
{
    // GIVEN
    MyContainer<int> container(5);
    int lastIndex = 4;
    for (int i = 0; i < lastIndex + 1; ++i)
        container[i] = i * 10;

    // WHEN/THEN
    ASSERT_EQ(*(--(container.end())), container[lastIndex]);
}

TEST(ContainersIteratorTest, ShouldItereteThroughContainer)
{
    // GIVEN
    MyContainer<int> container(5);
    for (int i = 0; i < 5; ++i)
        container[i] = i * 10;

    // WHEN
    int i = 0;
    for (auto it = container.begin(); it != container.end(); ++it, ++i)
    {
        // THEN
        ASSERT_EQ(*it, i * 10);
    }
}

}