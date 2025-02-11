#include <gtest/gtest.h>
#include <memory>

#include "open_closed_principle_geometry_violation.h"
#include "open_closed_principle_geometry_compliant.h"

// new geometry shape require modification of existing calculateArea class
TEST(OpenClosedPrincipleTest, TestPrincipleViolationGeometry)
 {
    // GIVEN
    ocp_violated_geometry::Rectangle rectangle(10, 2);
    ocp_violated_geometry::AreaCalculator calculator;

    // WHEN
    auto area = calculator.calculateArea(rectangle);

    // THEN
    EXPECT_EQ(area, 20);
}

// new geometry shape doesnt require modification of existing code (just implmenting new sub-class)
TEST(OpenClosedPrincipleTest, TestPrincipleComplyGeometry) 
{
    // GIVEN
    std::unique_ptr<ocp_compliant_geometry::Shape> shape = std::make_unique<ocp_compliant_geometry::Rectangle>(10, 2);

    // WHEN
    auto area = shape->getArea();

    // THEN
    EXPECT_EQ(area, 20);
}