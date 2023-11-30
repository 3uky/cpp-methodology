// https://www.cplusplus.com/reference/set/set/

// set - unique values, immutable, items could be removed or inserted but not modified, unordered set is more efficient for access by key less for iterating
// list - faster for inserting, moving, sorting, extracting than vector, array, deque. Cannot direct access by position.
// array - like c array it has static size, extended with methods
// vector - dynamic array
// map - association field, binary tree search (log n)
// unordered_map - association field, hash search (const)

#include "pch.h"

#pragma once

#include <set>

using namespace std;

using ::testing::UnorderedElementsAre;

namespace basic_elements
{

TEST(ContainersSetTest, ShouldContainUniqueValues)
{
    // GIVEN
    int myints[] = { 75, 23, 65, 42, 13, 75, 65, 9 };

    // WHEN
    set<int> myset(myints, myints + sizeof(myints) / sizeof(int));

    // THEN
    ASSERT_THAT(myset, UnorderedElementsAre( 75, 23, 65, 42, 13, 9 ));
}

}