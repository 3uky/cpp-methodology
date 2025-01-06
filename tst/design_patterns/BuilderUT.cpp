#include "gmock/gmock.h"

#include "Builder.h"
#include <memory>

using namespace std;

using ::testing::ElementsAre;

namespace design_patterns
{
    TEST(BuilderTest, ShouldBuildProduct)
    {
        // GIVEN
        std::shared_ptr<Builder> builder = std::make_shared<ConcreteBuilder1>();

        // WHEN
        builder->ProducePartA();
        builder->ProducePartB();

        // THEN
        EXPECT_THAT(builder->GetProduct()->GetParts(), ElementsAre("PartA1", "PartB1"));
    }

    TEST(BuilderTest, ShouldDirectorBuildMinimalViableProduct)
    {
        // GIVEN
        Director director = Director();
        std::shared_ptr<Builder> builder = std::make_shared<ConcreteBuilder1>();
        director.set_builder(builder);

        // WHEN
        director.BuildMinimalViableProduct();

        // THEN
        EXPECT_THAT(builder->GetProduct()->GetParts(), ElementsAre("PartA1"));
    }

    TEST(BuilderTest, ShouldDirectorBuildFullFeaturedProduct)
    {
        // GIVEN
        Director director = Director();
        std::shared_ptr<Builder> builder = std::make_shared<ConcreteBuilder1>();
        director.set_builder(builder);

        // WHEN
        director.BuildFullFeaturedProduct();

        // THEN
        EXPECT_THAT(builder->GetProduct()->GetParts(), ElementsAre("PartA1", "PartB1", "PartC1"));
    }
}