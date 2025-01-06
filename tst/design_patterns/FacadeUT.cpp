#include "gmock/gmock.h"

#include "Facade.h"

using namespace std;

namespace design_patterns
{

TEST(FacadeTest, ShouldInteractThroughFacadeAndReturnExpectedNumberOfCalls)
{
	// GIVEN
    FacilitiesFacade facilities;
    constexpr int expected_number_of_calls = 35;

	// WHEN
    facilities.submitNetworkRequest();
    while (!facilities.checkOnStatus()); // Keep checking until job is complete

	// THEN
    EXPECT_EQ(facilities.getNumberOfCalls(), expected_number_of_calls);
}

}
