#include "gmock/gmock.h"

#include "OverloadingOperators.h"

namespace basic_elements
{
    TEST(OverloadingOperators, ShouldAddComplexNumbers) 
    {
        // GIVEN
        ComplexNumber foo(3, 4);
        ComplexNumber bar(1, 2);
        ComplexNumber result;

        // WHEN
        result = foo + bar;

        // THEN
        EXPECT_EQ(result.getReal(), 4);
        EXPECT_EQ(result.getImaginary(), 6);
    }

    TEST(OverloadingOperators, ShouldSubstractComplexNumbers) 
    {
        // GIVEN
        ComplexNumber foo(3, 4);
        ComplexNumber bar(1, 2);
        ComplexNumber result;

        // WHEN
        result = foo - bar;

        // THEN
        EXPECT_EQ(result.getReal(), 2);
        EXPECT_EQ(result.getImaginary(), 2);
    }

    TEST(OverloadingOperators, ShouldDivideComplexNumbers) 
    {
        // GIVEN
        ComplexNumber foo(3, 4);
        ComplexNumber bar(1, 2);
        ComplexNumber result;

        // WHEN
        result = foo / bar;

        // THEN
        EXPECT_EQ(result.getReal(), 2.2);
        EXPECT_EQ(result.getImaginary(), -0.4);
    }
    
    TEST(OverloadingOperators, ShouldMultiplyComplexNumbers) 
    {
        // GIVEN
        ComplexNumber foo(3, 4);
        ComplexNumber bar(1, 2);
        ComplexNumber result;

        // WHEN
        result = foo * bar;

        // THEN
        EXPECT_EQ(result.getReal(), -5);
        EXPECT_EQ(result.getImaginary(), 10);
    }

    TEST(OverloadingOperators, ShouldComputeComplexNumbers) 
    {
        // GIVEN
        ComplexNumber foo(3, 4);
        ComplexNumber result;

        // WHEN / THEN
        EXPECT_EQ(foo.getMagnitude(), 5.0);
    }


}