#include "pch.h"
#include "LinkedList.h"

#include <list>

using namespace std;
using ::testing::ElementsAre;

namespace cpp_internals
{
TEST(LinkedLIstTest, ShouldAccessFirstElement)
{
	// GIVEN
	LinkedList<int> test_list;

	// WHEN
	test_list.Insert(5);
	test_list.Insert(6);
	test_list.Insert(7);

	// THEN
	EXPECT_EQ(test_list.Front(), 5);
}

TEST(LinkedLIstTest, ShouldDeleteValueOnSpecifiedPosition)
{
	// GIVEN
	LinkedList<int> test_list;
	test_list.Insert(5);
	test_list.Insert(6);
	test_list.Insert(7);

	// WHEN
	test_list.Remove(1);

	// THEN
	EXPECT_EQ(test_list.Get(0), 5);
	EXPECT_EQ(test_list.Get(1), 7);
}

TEST(LinkedLIstTest, ShouldInsertValues)
{
	// GIVEN
	LinkedList<int> test_list;

	// WHEN
	test_list.Insert(5);
	test_list.Insert(6);
	test_list.Insert(7);

	// THEN
	EXPECT_EQ(test_list.Get(0), 5);
	EXPECT_EQ(test_list.Get(1), 6);
	EXPECT_EQ(test_list.Get(2), 7);
}


TEST(LinkedListTest, ShouldReverseValuesOfStdList)
{
	// GIVEN
	std::list<int> test_list = { 1, 2, 3, 4, 5 };

	// WHEN
	test_list.reverse();

	// THEN
	EXPECT_THAT(test_list, ElementsAre(5, 4, 3, 2, 1));

}

TEST(LinkedLIstTest, ShouldSwapElements)
{
	// GIVEN
	LinkedList<int> test_list;
	test_list.Insert(5);
	test_list.Insert(6);
	test_list.Insert(7);

	// WHEN
	test_list.Swap(0, 2);
	
	// THEN
	EXPECT_EQ(test_list.Get(0), 7);
	EXPECT_EQ(test_list.Get(1), 6);
	EXPECT_EQ(test_list.Get(2), 5);
}

TEST(LinkedLIstTest, ShouldReturnExactCountOfElements)
{	// GIVEN
	LinkedList<int> test_list;
	test_list.Insert(5);
	test_list.Insert(6);
	test_list.Insert(7);

	// WHEN
	EXPECT_EQ(test_list.Count(), 3);
}


TEST(LinkedLIstTest, ShouldReverseElements)
{
	// GIVEN
	LinkedList<int> test_list;
	test_list.Insert(5);
	test_list.Insert(6);
	test_list.Insert(7);
	test_list.Insert(8);

	// WHEN
	test_list.Reverse();

	// THEN
	EXPECT_EQ(test_list.Get(0), 8);
	EXPECT_EQ(test_list.Get(1), 7);
	EXPECT_EQ(test_list.Get(2), 6);
	EXPECT_EQ(test_list.Get(3), 5);
}

TEST(LinkedLIstTest, ShouldRetrunLastElement)
{
	// GIVEN
	LinkedList<int> test_list;
	test_list.Insert(5);
	test_list.Insert(6);
	test_list.Insert(7);
	test_list.Insert(8);

	// WHEN/THEN
	EXPECT_EQ(test_list.Back(), 8);
}

}