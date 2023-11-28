#include "pch.h"
#include "UniqueNames.h"

using namespace std;

using ::testing::ElementsAre;

namespace exercises
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