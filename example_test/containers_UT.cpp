// https://www.cplusplus.com/reference/set/set/

// set - unique values, immutable, items could be removed or inserted but not modified, unordered set is more efficient for access by key less for iterating
// list - faster for inserting, moving, sorting, extracting than vector, array, deque. Cannot direct access by position.
// array - like c array it has static size, extended with methods
// vector - dynamic array
// map - association field, binary tree search (log n)
// unordered_map - association field, hash search (const)



#include "pch.h"

#pragma once

#include <vector>
#include <list>
#include <array>
#include <set>

using namespace std;

using ::testing::ElementsAre;
using ::testing::UnorderedElementsAre;

namespace basic_elements
{

TEST(ContainersVectorTest, ShouldBeInitializedWithRange)
{
    // GIVEN/WHEN
    std::vector<int> tested_vector(3, 100);


    // THEN
    ASSERT_THAT(tested_vector, ElementsAre(100, 100, 100));
}

TEST(ContainersVectorTest, ShouldBeInitializedWithIterator)
{
    // GIVEN
    std::vector<int> tested_vector { 100, 100, 100 };
    std::vector<int>::iterator it = tested_vector.begin();

    // WHEN
    it = tested_vector.insert(it, 200); // 200 100 100 100
    tested_vector.insert(it, 2, 300); // 300 300 200 100 100 1000

    // THEN
    ASSERT_THAT(tested_vector, ElementsAre(300, 300, 200, 100, 100, 100));
}

TEST(ContainersVectorTest, ShouldBeInitializedWithAnotherVector)
{
    // GIVEN
    std::vector<int> tested_vector = { 300, 300, 200, 100, 100, 100 };
    std::vector<int> tested_vector_2(2, 400);
    std::vector<int>::iterator it = tested_vector.begin();

    // WHEN
    tested_vector.insert(it + 2, tested_vector_2.begin(), tested_vector_2.end()); // 300 300 400 400 200 100 100 100

    // THEN
    ASSERT_THAT(tested_vector, ElementsAre( 300, 300, 400, 400, 200, 100, 100, 100 ));
}

TEST(ContainersVectorTest, ShouldBeInitializedWithArray)
{
    // GIVEN
    std::vector<int> tested_vector(2, 400);
    int array[] = { 501, 502, 503 };

    // WHEN
    tested_vector.insert(tested_vector.begin(), array, array + 3); // 501 502 503 400 400

    // THEN
    ASSERT_THAT(tested_vector, ElementsAre( 501, 502, 503, 400, 400 ));
}

TEST(ContainersSetTest, ShouldContainUniqueValues)
{
    // GIVEN
    int myints[] = { 75, 23, 65, 42, 13, 75, 65, 9 };

    // WHEN
    set<int> myset(myints, myints + sizeof(myints) / sizeof(int));

    // THEN
    ASSERT_THAT(myset, UnorderedElementsAre( 75, 23, 65, 42, 13, 9 ));
}

TEST(ContainersArrayTest, ShouldInitializeArray)
{
    // GIVEN
    std::array<int, 3> tested_array;

    // WHEN
    for (int i = 0; i < 3; i++)
        tested_array.at(i) = i + 1;

    // THEN
    ASSERT_THAT(tested_array, ElementsAre(1, 2, 3));
}

TEST(ContainersMapTest, ShouldInitializeMap)
{
	// GIVEN/WHEN
    std::map<char, int> tested_map;
    std::map<char, int> tested_map_2 = { {'a', 10}, {'b', 30}, {'c', 50}, {'d', 70} };
    std::map<char, int> tested_map_3(tested_map_2.begin(), tested_map_2.end());
    tested_map['a'] = 10;
    tested_map['b'] = 30;
    tested_map['c'] = 50;
    tested_map['d'] = 70;

    // THEN
    EXPECT_TRUE(tested_map == tested_map_2);
    EXPECT_TRUE(tested_map == tested_map_3);
}

TEST(ContainersListTest, ShouldInitializeList)
{
    // GIVEN/WHEN
    std::list<int> tested_list(4, 100);

    // THEN
    ASSERT_THAT(tested_list, ElementsAre(100, 100, 100, 100));
}

}