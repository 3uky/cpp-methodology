#ifndef T_TEST_H
#define T_TEST_H

#include <iostream>
#include <vector>
#include <string>

class TextInput
{
public:
    std::string value;
    virtual void add(char c) { value+=c; }

    std::string getValue() { return value; }
};

class NumericInput : public TextInput {
public:
    void add(char c) { if(isdigit(c)) value+=c; }
};

class T_test
{
public:
    static std::vector<std::string> unique_names(const std::vector<std::string>& names1, const std::vector<std::string>& names2)
    {
        std::set<std::string> result;

        for (auto name : names1)
        {
            result.insert(name);
        }
        for (auto name : names2)
        {
            result.insert(name);
        }

        vector<std::string> result_v(result.begin(), result.end());

        return result_v;
    }


    static void test_unique_names()
    {
        std::vector<std::string> names1 = {"Ava", "Emma", "Olivia"};
        std::vector<std::string> names2 = {"Olivia", "Sophia", "Emma"};

        std::vector<std::string> result = unique_names(names1, names2);
        for(auto element : result)
        {
            std::cout << element << ' '; // should print Ava Emma Olivia Sophia
        }
    }

    static void test_letters()
    {
        TextInput* input = new NumericInput();
        input->add('1');
        input->add('a');
        input->add('0');
        std::cout << input->getValue();
    }


    static void test()
    {
        //test_unique_names();
        test_letters();
    }

};

#endif // T_TEST_H
