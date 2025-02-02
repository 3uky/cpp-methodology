#include "gmock/gmock.h"

#include "frequency_sort.h"

using ::testing::ElementsAre;

namespace leet_code
{
    TEST(FrequencySortTest, ShouldSortSequenceBasedOnFrequency)
    {
        // GIVEN
        FrequencySort frequencySort;
		
		std::vector<int> tested_arr = { 10, 7, 7, 8, 9, 9, 9 , 9, 1 ,1, 1, 5 };

		// WHEN/THEN
		EXPECT_THAT(frequencySort.Sort(tested_arr), ElementsAre(9, 1, 7, 10, 8, 5));
    }
}
