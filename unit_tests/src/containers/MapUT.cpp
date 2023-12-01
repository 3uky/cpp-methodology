// https://www.cplusplus.com/reference/set/set/

// set - unique values, immutable, items could be removed or inserted but not modified, unordered set is more efficient for access by key less for iterating
// list - faster for inserting, moving, sorting, extracting than vector, array, deque. Cannot direct access by position.
// array - like c array it has static size, extended with methods
// vector - dynamic array
// map - association field, binary tree search (log n)
// unordered_map - association field, hash search (const)

#include "gmock/gmock.h"

#pragma once

#include <map>

namespace basic_elements
{

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

}