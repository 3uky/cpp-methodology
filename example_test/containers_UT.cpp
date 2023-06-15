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

namespace basic_elements
{

TEST(ContainersVectorTest, ShouldBeInitializedWithRange)
{
    // GIVEN
    std::vector<int> expected_vector{100, 100, 100};

    // WHEN
    std::vector<int> tested_vector(3, 100);


    // THEN
    EXPECT_TRUE(tested_vector == expected_vector);
}

TEST(ContainersVectorTest, ShouldBeInitializedWithIterator)
{
    // GIVEN
    std::vector<int> expected_vector{ 300, 300, 200, 100, 100, 100 };
    std::vector<int> tested_vector { 100, 100, 100 };
    std::vector<int>::iterator it = tested_vector.begin();

    // WHEN
    it = tested_vector.insert(it, 200); // 200 100 100 100
    tested_vector.insert(it, 2, 300); // 300 300 200 100 100 1000

    // THEN
    EXPECT_TRUE(tested_vector == expected_vector);
}

TEST(ContainersVectorTest, ShouldBeInitializedWithAnotherVector)
{
    // GIVEN
    std::vector<int> expected_vector = { 300, 300, 400, 400, 200, 100, 100, 100 };
    std::vector<int> tested_vector = { 300, 300, 200, 100, 100, 100 };
    std::vector<int> tested_vector_2(2, 400);
    std::vector<int>::iterator it = tested_vector.begin();

    // WHEN
    tested_vector.insert(it + 2, tested_vector_2.begin(), tested_vector_2.end()); // 300 300 400 400 200 100 100 100

    // THEN
    EXPECT_TRUE(tested_vector == expected_vector);
}

TEST(ContainersVectorTest, ShouldBeInitializedWithArray)
{
    // GIVEN
    std::vector<int> expected_vector = { 501, 502, 503, 400, 400 };
    std::vector<int> tested_vector(2, 400);
    int array[] = { 501, 502, 503 };

    // WHEN
    tested_vector.insert(tested_vector.begin(), array, array + 3); // 501 502 503 400 400

    // THEN
    EXPECT_TRUE(tested_vector == expected_vector);
}

TEST(ContainersSetTest, ShouldContainUniqueValues)
{
    // GIVEN
    int myints[] = { 75, 23, 65, 42, 13, 75, 65, 9 };
    set<int> myset(myints, myints + sizeof(myints) / sizeof(int));
    set<int> myset2 = { 75, 23, 65, 42, 13, 9 };

    // THEN
    EXPECT_EQ(myset, myset2);
}

TEST(ContainersArrayTest, ShouldInitializeArray)
{
    std::array<int, 3> expected_array = { 0, 1, 2};
    std::array<int, 3> tested_array;

    for (int i = 0; i < 3; i++)
        tested_array.at(i) = i + 1;

    EXPECT_TRUE(tested_array == expected_array);
}


TEST(ContainersMapTest, ShouldInitializeMap)
{
    std::map<char, int> tested_map;

    tested_map['a'] = 10;
    tested_map['b'] = 30;
    tested_map['c'] = 50;
    tested_map['d'] = 70;

    std::map<char, int> tested_map_2(tested_map.begin(), tested_map.end());

    EXPECT_TRUE(tested_map == tested_map_2);
}

TEST(ContainersListTest, ShouldInitializeList)
{
    // GIVEN/WHEN
    std::list<int> expected_list = {100, 100, 100, 100};
    std::list<int> tested_list(4, 100);

    // THEN
    EXPECT_TRUE(tested_list == expected_list);
}

}