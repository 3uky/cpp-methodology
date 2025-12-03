#include <gtest/gtest.h>

#include "liskov_substitution_principle_geometry_violation.h"
#include "liskov_substitution_principle_geometry_compliant.h"

// if Square inherit from Rectangle you can call setWidth and setHeight but square sides should always be equal
// setting width to 5 and height to 10 result in undefined behavior the expected area should be invalid
// Square is not interchangable for Rectangle and LSP principle is violated
TEST(LiskovSubstitutionPrincipleTest, TestPrincipleViolation) 
{
    lsp_violated_geometry::Rectangle rect;
    lsp_violated_geometry::Square square;

    rect.setWidth(5.0);
    rect.setHeight(10.0);

    square.setWidth(5.0);
    square.setHeight(10.0);

    EXPECT_DOUBLE_EQ(square.getArea(), 100.0);  // NOT correct for a square anymore!   
    EXPECT_DOUBLE_EQ(rect.getArea(), 50.0);
}

// square inherit from Shape now and setting width and height is not possible anymore
// Square is interchangable for Shape and LSP is not violated
TEST(LiskovSubstitutionPrincipleTest, TestsPrincipleCompliant) 
{
    lsp_compliant_geometry::Rectangle rect;
    lsp_compliant_geometry::Square square;

    rect.setWidth(5.0);
    rect.setHeight(10.0);

    square.setSide(5.0);

    EXPECT_DOUBLE_EQ(rect.getArea(), 50.0);
    EXPECT_DOUBLE_EQ(square.getArea(), 25.0);    
}
