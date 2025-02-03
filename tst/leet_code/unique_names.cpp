#include "gmock/gmock.h"

#include "unique_names.h"

using ::testing::ElementsAre;

namespace leet_code
{
    TEST(UniqueNamesTest, ShouldReturnUniqueNames)
    {
        // GIVEN
        std::vector<std::string> names_1 = { "Ava", "Emma", "Olivia" };
        std::vector<std::string> names_2 = { "Olivia", "Sophia", "Emma" };

        // WHEN
        std::vector<std::string> result = UniqueNames::GetUniqueNames(names_1, names_2);

        // THEN
        ASSERT_THAT(result, ElementsAre("Ava", "Emma", "Olivia", "Sophia"));
    }
}