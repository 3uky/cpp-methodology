#include "gmock/gmock.h"

#include "shuffle.h"

#include <array>

using namespace std;
using testing::ElementsAre;
using testing::Not;

namespace algorithms
{


TEST(ShuffleTest, ShouldShuffleSortenArray)
{
	MySort mySort;

	std::array<int, 5> myArray = { 1, 2, 3, 4, 5 };

	mySort.Shuffle(myArray);

	EXPECT_THAT(myArray, Not(ElementsAre(1, 2, 3, 4, 5)));
}

}
