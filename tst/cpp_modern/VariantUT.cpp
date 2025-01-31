#include <gtest/gtest.h>

#include <variant>
#include <string>
#include <iostream>

namespace basic_elements
{

TEST(VariantTest, HoldsInt)
{
    // GIVEN
    std::variant<int, double, std::string> v = 42;

    // WHEN / THEN
    EXPECT_TRUE(std::holds_alternative<int>(v));
    EXPECT_EQ(std::get<int>(v), 42);
}

TEST(VariantTest, HoldsDouble) 
{
    // GIVEN
    std::variant<int, double, std::string> v = 3.14;

    // WHEN / THEN
    EXPECT_TRUE(std::holds_alternative<double>(v));
    EXPECT_EQ(std::get<double>(v), 3.14);
}

TEST(VariantTest, HoldsString)
{
    // GIVEN
    std::variant<int, double, std::string> v = "Hello, world!";

    // WHEN / THEN
    EXPECT_TRUE(std::holds_alternative<std::string>(v));
    EXPECT_EQ(std::get<std::string>(v), "Hello, world!");
}

TEST(VariantTest, InvalidGet) {
    // GIVEN
    std::variant<int, double, std::string> v = 42;

    // WHEN / THEN
    EXPECT_THROW(std::get<double>(v), std::bad_variant_access);
}

TEST(VariantTest, HoldsEmptyVariant) {
    // GIVEN
    // default constructor intialize actual variant with first variant type in this case
    // it's monostate which represents empty state
    std::variant<std::monostate, double, int> empty;

    // WHEN / THEN
    EXPECT_FALSE(std::holds_alternative<int>(empty));
    EXPECT_FALSE(std::holds_alternative<double>(empty));
}

}