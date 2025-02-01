#include "gmock/gmock.h"

#include "type_conversions.h"

namespace basic_elements
{

TEST(TypeConversionTest, ShouldDynamicDownCastToDerivedClass)
{
    // GIVEN
    Base* b = new Derived;
    Derived* d;

    // WHEN
	//d = b; // base class pointer assigned to the derived class pointer
	d = dynamic_cast<Derived*>(b); // to promote down-casting

	// THEN
	EXPECT_EQ(d->GetType(), ObjectType::DerivedObject);
}

TEST(TypeConversionTest, ShouldDemonstrateConversions)
{
    A o_A;
    B o_B(o_A); // explicit conversion
    o_B = o_A;  // assignment conversion
    o_A = o_B;  // type-cast operator
}

};
