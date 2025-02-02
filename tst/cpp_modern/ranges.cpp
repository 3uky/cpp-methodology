#include <gtest/gtest.h>
#include <ranges>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

namespace cpp_modern
{

std::vector<int> sample_vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

TEST(RangesTest, FilterEvenNumbers)
{
    // GIVEN
    std::vector<int> expected = {2, 4, 6, 8, 10};
    
    // WHEN
    auto even_numbers = sample_vec | std::ranges::views::filter([](int x) { return x % 2 == 0; }); 

    // THEN
    std::vector<int> result(even_numbers.begin(), even_numbers.end()); // Convert the range into a vector
    EXPECT_EQ(result, expected);
}

TEST(RangesTest, SortRange)
{
    // GIVEN
    std::vector<int> shuffled = {10, 2, 9, 4, 7, 6, 3, 1, 8, 5};
    std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // WHEN
    std::ranges::sort(shuffled);

    // THEN
    EXPECT_EQ(shuffled, expected);
}

struct CustomRange 
{
    std::vector<int> data;

    auto begin() 
    { 
        return data.begin();
    }

    auto end()
    { 
        return data.end(); 
    }
};

TEST(RangesTest, CustomRangeSort)
{
    // GIVEN
    CustomRange custom_range{{4, 2, 5, 1, 3}};

    // WHEN
    std::ranges::sort(custom_range.data);

    // THEN
    ASSERT_EQ(custom_range.data, std::vector<int>({1, 2, 3, 4, 5}));
}

TEST(RangesTest, JoinStringRanges)
{
    // GIVEN
    std::vector<std::vector<std::string>> vec_of_strings = {{"Hello", "world"}, {"This", "is", "C++"}};
    std::vector<std::string> expected = {"Hello", "world", "This", "is", "C++"};

    // WHEN
    auto joined = vec_of_strings | std::ranges::views::join;

    // THEN
    std::vector<std::string> result(joined.begin(), joined.end());
    EXPECT_EQ(result, expected);
}

TEST(RangesTest, AllOfCheck) 
{
    // WHEN
    auto all_positive = std::ranges::all_of(sample_vec, [](int x) { return x > 0; });

    // THEN
    EXPECT_TRUE(all_positive);
}

TEST(RangesTest, FindElementInRange) 
{
    // WHEN
    auto it = std::ranges::find(sample_vec, 5);

    // THEN
    EXPECT_NE(it, sample_vec.end());
    EXPECT_EQ(*it, 5);
}

TEST(RangesTest, ReverseRange) 
{
    // GIVEN
    std::vector<int> expected = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    // WHEN
    auto reversed = sample_vec | std::ranges::views::reverse;
   
    // THEN
    std::vector<int> result(reversed.begin(), reversed.end());
    EXPECT_EQ(result, expected);
}

TEST(RangesTest, TransformToUppercase) 
{
    // GIVEN
    std::vector<std::string> words = {"hello", "world", "foo", "bar"};
    std::vector<std::string> expected = {"HELLO", "WORLD", "FOO", "BAR"};

    // WHEN
    auto result = words | std::ranges::views::transform([](std::string s)
    {
        std::ranges::transform(s.begin(), s.end(), s.begin(), ::toupper);
        return s;
    });

    // THEN
    std::vector<std::string> transformed(result.begin(), result.end());
    EXPECT_EQ(transformed, expected);
}

TEST(RangesTest, TakeFirstFewElements)
{
    // GIVEN
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> expected = {1, 2, 3, 4, 5};
       
    // WHEN
    auto result_split = numbers | std::ranges::views::split(6);

    // THEN
    auto result = *result_split.begin(); // extract first subrange
    std::vector<int> taken(result.begin(), result.end());
    EXPECT_EQ(taken, expected);
}

TEST(RangesTest, GenerateSequenceWithIota)
{
    // GIVEN
    std::vector<int> expected = {1, 2, 3, 4, 5};

    // WHEN
    auto result = std::ranges::views::iota(1, 6);

    // THEN
    std::vector<int> generated(result.begin(), result.end());
    EXPECT_EQ(generated, expected);
}

TEST(RangesTest, ForEachApplyFunction)
{
    // GIVEN
    std::vector<int> data = {1, 2, 3, 4, 5};
    int sum = 0;

    // WHEN
    std::ranges::for_each(data, [&sum](int num) { sum += num; });

    // THEN
    ASSERT_EQ(sum, 15);
}

}