#include "pch.h"
#include "overloading_operators.h"

namespace basic_paradigm
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