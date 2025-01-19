#include "gmock/gmock.h"

#include "OverloadingOperators.h"

namespace basic_elements
{
    TEST(OverloadingOperators, ShouldOverloadComplexNumberOperator) 
    {
        // GIVEN
        ComplexNumber foo(3, 1);
        ComplexNumber bar(1, 2);
        ComplexNumber result;

        // WHEN
        result = foo + bar;

        // THEN
        EXPECT_EQ(result.getReal(), 4);
        EXPECT_EQ(result.getImaginary(), 3);
    }
}