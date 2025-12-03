#include "gmock/gmock.h"

#include "linked_list.h"

#include <list>

using namespace std;
using ::testing::ElementsAre;

namespace containers
{

class LinkedListTest : public testing::Test
{
protected:
	void SetUp()
	{
		test_list.Insert(5);
		test_list.Insert(6);
		test_list.Insert(7);
	}

	LinkedList<int> test_list;
};

TEST_F(LinkedListTest, ShouldAccessFirstElement)
{
	// THEN
	EXPECT_EQ(test_list.Front(), 5);
}

TEST_F(LinkedListTest, ShouldDeleteValueOnSpecifiedPosition)
{
	// WHEN
	test_list.Remove(1);

	// THEN
	EXPECT_EQ(test_list.Get(0), 5);
	EXPECT_EQ(test_list.Get(1), 7);
}

TEST_F(LinkedListTest, ShouldInsertValues)
{
	// THEN
	EXPECT_EQ(test_list.Get(0), 5);
	EXPECT_EQ(test_list.Get(1), 6);
	EXPECT_EQ(test_list.Get(2), 7);
}

TEST_F(LinkedListTest, ShouldSwapElements)
{
	// WHEN
	test_list.Swap(0, 2);
	
	// THEN
	EXPECT_EQ(test_list.Get(0), 7);
	EXPECT_EQ(test_list.Get(1), 6);
	EXPECT_EQ(test_list.Get(2), 5);
}

TEST_F(LinkedListTest, ShouldReturnExactCountOfElements)
{
	// WHEN
	EXPECT_EQ(test_list.Count(), 3);
}

TEST_F(LinkedListTest, ShouldReverseElements)
{
	// WHEN
	test_list.Reverse();

	// THEN
	EXPECT_EQ(test_list.Get(0), 7);
	EXPECT_EQ(test_list.Get(1), 6);
	EXPECT_EQ(test_list.Get(2), 5);
}

TEST_F(LinkedListTest, ShouldRetrunLastElement)
{
	// WHEN/THEN
	EXPECT_EQ(test_list.Back(), 7);
}

TEST(StdLinkedListTest, ShouldReverseValuesOfStdList)
{
	// GIVEN
	std::list<int> test_list = { 1, 2, 3, 4, 5 };

	// WHEN
	test_list.reverse();

	// THEN
	EXPECT_THAT(test_list, ElementsAre(5, 4, 3, 2, 1));
}

}