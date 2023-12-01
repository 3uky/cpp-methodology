// https://www.cplusplus.com/reference/set/set/

// set - unique values, immutable, items could be removed or inserted but not modified, unordered set is more efficient for access by key less for iterating
// list - faster for inserting, moving, sorting, extracting than vector, array, deque. Cannot direct access by position.
// array - like c array it has static size, extended with methods
// vector - dynamic array
// map - association field, binary tree search (log n)
// unordered_map - association field, hash search (const)

#include "gmock/gmock.h"

#pragma once

#include <list>

using ::testing::ElementsAre;

namespace basic_elements
{

TEST(ContainersListTest, ShouldInitializeList)
{
    // GIVEN/WHEN
    std::list<int> tested_list(4, 100);

    // THEN
    ASSERT_THAT(tested_list, ElementsAre(100, 100, 100, 100));
}

}