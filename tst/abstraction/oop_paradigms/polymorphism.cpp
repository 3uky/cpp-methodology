#include "gmock/gmock.h"

#include "polymorphism.h"

namespace oop_paradigm
{

TEST(PolymorphismTest, ShouldBePolymorphicWithStaticInitialization)
{
    // GIVEN
    Rectangle rectangle;
    Triangle triangle;
    Polygon* polymorphic_rectangle = &rectangle;
    Polygon* polymorphic_triangle = &triangle;

    // WHEN
    polymorphic_rectangle->set_values(4, 5);
    polymorphic_triangle->set_values(4, 5);

    // THEN
    EXPECT_EQ(polymorphic_rectangle->area(), 20);
    EXPECT_EQ(polymorphic_triangle->area(), 10);

    //cout << "static init rect(4x5): " << ppoly1->area() << endl;
    //cout << "static init trgl(4x5): " << ppoly2->area() << endl;
}

TEST(PolymorphismTest, ShouldBePolymorphicWithDynamicInitialization)
{
    // GIVEN
    Polygon* polygon = new Rectangle();

    // WHEN
    polygon->set_values(4, 5);

    // THEN
    EXPECT_EQ(polygon->area(), 20);

    // cout << "dynamic init rect(4x5): " << polymorphic_rectangle->area() << endl;

    // CLEANUP
    delete polygon;
}

TEST(PolymorphismTest, ShouldBePolymorphicWithDynamicSharedPointerInitialization)
{
    // GIVEN
    std::shared_ptr<Polygon> polygon = std::make_shared<Rectangle>();

    // WHEN
    polygon->set_values(4, 5);

    // THEN
    EXPECT_EQ(polygon->area(), 20);

    //cout << "shared ptr rect(4x5): " << polygon->area() << endl;
}

TEST(PolymorphismTest, ShouldBePolymorphicWithDynamicUniquePointerInitialization)
{
    // GIVEN
    std::unique_ptr<Polygon> polygonA = std::make_unique<Rectangle>();
    std::unique_ptr<Polygon> polygonB = std::make_unique<Triangle>();

    // WHEN
    polygonA->set_values(4, 5);
    polygonB->set_values(4, 5);

    // THEN
    EXPECT_EQ(polygonA->area(), 20);
    EXPECT_EQ(polygonB->area(), 10);
}

}