#include "gmock/gmock.h"

#include "my_container.h"
#include "iterator.h"

using ::testing::ElementsAre;

namespace containers
{

// shallow copy of dynamicly allocated memory could lead to multiple delelte of same memory
TEST(ContainersIteratorTest, ShouldPreventMultipleMemoryFree)
{
    // GIVEN
    MyContainer<int> container(5);
    MyContainer<int> containerB(5);

    // WHEN / THEN
    containerB = containerB;    
}

TEST(ContainersIteratorTest, ShouldIncrementInterator)
{
    // GIVEN
    MyContainer<int> container(5);
    container[0] = 10;
    container[1] = 20;
    
    // WHEN
    Iterator it = container.begin();
    ++it;

    // THEN
    EXPECT_EQ(*it, 20);
}

TEST(ContainersIteratorTest, ShouldDecrementInterator)
{
    // GIVEN
    MyContainer<int> container(5);
    container[0] = 10;
    container[1] = 20;

    // WHEN
    Iterator it = Iterator<int>(container.data + 1);
    --it;

    // THEN
    EXPECT_EQ(*it, 10);
}

TEST(ContainersIteratorTest, ShouldSetItaratorToContainerBegin)
{
    // GIVEN
    MyContainer<int> container(5);
    container[0] = 10;
    
    // WHEN
    Iterator it = container.begin();

    // THEN
    EXPECT_EQ(*it, 10);
}

TEST(ContainersIteratorTest, ShouldSetItaratorToContainerEnd)
{
    // GIVEN
    MyContainer<int> container(5);
    container[4] = 10;
    
    // WHEN
    Iterator it = container.end();

    // THEN
    // end points after last element and should be decremented
    EXPECT_EQ(*(--it), 10);
}

TEST(ContainersIteratorTest, ShouldIterateThroughForCycle)
{
    // GIVEN
    std::vector<int> expected = {0,0,0,3,0};
    MyContainer<int> container(5);
    container[3] = 3;   

    // WHEN / THEN
    int i = 0;
    for(auto it = container.begin(); it != container.end(); ++it)
    {
        EXPECT_EQ(*it, expected.at(i++));   
    }    
}

}