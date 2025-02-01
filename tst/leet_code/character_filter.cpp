#include "gmock/gmock.h"

#include "character_filter.h"

using namespace std;

namespace exercises
{
    TEST(CharacterFilterTest, ShouldFilterJustNumericLetters)
    {
        // GIVEN
        TextInput* input = new NumericInput();

        // WHEN
    	input->add('1');
        input->add('a');
        input->add('0');

        // THEN
        EXPECT_EQ(input->getValue(), "10");
    }
}