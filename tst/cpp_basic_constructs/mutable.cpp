#include "gmock/gmock.h"

#include "mutable.h"

namespace cpp_basic_constructs
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