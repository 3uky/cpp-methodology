// https://www.cplusplus.com/reference/set/set/

// set - unique values, immutable, items could be removed or inserted but not modified, unordered set is more efficient for access by key less for iterating
// list - faster for inserting, moving, sorting, extracting than vector, array, deque. Cannot direct access by position.
// array - like c array it has static size, extended with methods
// vector - dynamic array
// map - association field, binary tree search (log n)
// unordered_map - association field, hash search (const)

#include "gmock/gmock.h"

#pragma once

#include <vector>

using ::testing::ElementsAre;

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

}