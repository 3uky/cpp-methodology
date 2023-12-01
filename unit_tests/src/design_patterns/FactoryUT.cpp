#include "gmock/gmock.h"

#include "factory.h"

#include <array>

using namespace std;

namespace design_patterns
{

TEST(FactoryTest, ShouldFactoryGenerateExpectedObject)
{
	// GIVEN
	vector<unique_ptr<IObject>> roles;
	constexpr ObjectType choiceA = ObjectA;
	constexpr ObjectType choiceB = ObjectB;
	constexpr ObjectType choiceC = ObjectC;

	// WHEN
	std::unique_ptr<IObject> objectA = Factory::MakeObject(choiceA);
	std::unique_ptr<IObject> objectB = Factory::MakeObject(choiceB);
	std::unique_ptr<IObject> objectC = Factory::MakeObject(choiceC);
	
	// THEN
	EXPECT_EQ(objectA->GetType(), ObjectType::ObjectA);
	EXPECT_EQ(objectB->GetType(), ObjectType::ObjectB);
	EXPECT_EQ(objectC->GetType(), ObjectType::ObjectC);
}

}