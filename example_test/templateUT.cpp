#include "pch.h"
#include "include\template.h"

namespace basic_paradigm
{

TEST(TemplateTest, ShouldReturnSummaryThroughTemplatedMethod) {
    EXPECT_EQ(MyTemplate::sum<int>(10, 20), 30);
    EXPECT_EQ(MyTemplate::sum<float>(1.0, 1.5), 2.5);
    EXPECT_EQ(MyTemplate::sum<string>("Hello,", " World!"), "Hello, World!");
}

}