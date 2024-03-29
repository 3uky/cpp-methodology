#include "gmock/gmock.h"

#include "OverloadingOperators.h"

namespace basic_elements
{
    TEST(OverloadingOperators, ShouldOverloadVectorOperator) 
    {
        // GIVEN
        MyVector foo(3, 1);
        MyVector bar(1, 2);
        MyVector result;

        // WHEN
        result = foo + bar;

        // THEN
        EXPECT_EQ(result.getX(), 4);
        EXPECT_EQ(result.getY(), 3);
    }

}