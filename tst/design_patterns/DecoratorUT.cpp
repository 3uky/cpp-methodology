#include "gmock/gmock.h"

#include "Decorator.h"

using namespace std;

namespace design_patterns
{
    TEST(DecoratorTest, ShouldDecorateCoreObject)
    {
        // GIVEN / WHEN
        I* anX = new X(new A);
        I* anXY = new Y(new X(new A));
        I* anXYZ = new Z(new Y(new X(new A)));

    	// THEN
        EXPECT_EQ(anX->do_it(), "AX");
        EXPECT_EQ(anXY->do_it(), "AXY");
        EXPECT_EQ(anXYZ->do_it(), "AXYZ");

        delete anX;
        delete anXY;
        delete anXYZ; 
    };
    


}