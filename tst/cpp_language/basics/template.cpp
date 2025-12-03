#include "gmock/gmock.h"

#include "template.h"

namespace cpp_basic_constructs
{

TEST(TemplateTest, ShouldReturnSummaryThroughTemplatedMethod) {
    EXPECT_EQ(MyTemplate::sum<int>(10, 20), 30);
    EXPECT_EQ(MyTemplate::sum<float>(1.0, 1.5), 2.5);
    EXPECT_EQ(MyTemplate::sum<std::string>("Hello,", " World!"), "Hello, World!");
}

}