#include "gmock/gmock.h"

#pragma once

#include <memory>

using namespace std;

namespace basic_elements
{

TEST(SmartPointerUsageTest, ShouldInitializeAndGetSmartPointer)
{
    // GIVEN
    //std::shared_ptr<int> p1 (new int);
    std::shared_ptr<int> p1 = std::make_shared<int>();
	std::shared_ptr<int> p2(p1);

    // WHEN
	*p1.get() = 10;

    // THEN
    EXPECT_EQ(*p1, 10);
    EXPECT_EQ(*p1, *p2);
}

}