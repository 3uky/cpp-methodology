#include "pch.h"
#include "include\mutable.h"

using namespace std;

namespace basic_elements
{
    TEST(MutableTest, ShouldChangeMutableVariableInConstantMethod)
    {
        // GIVEN
        Mutable mutableObject;
        auto val1 = mutableObject.GetValue();

        // WHEN
        mutableObject.ChangeMutableVariable();
        auto val2 = mutableObject.GetValue();

        // THEN
    	EXPECT_NE(val1, val2);

    }

}