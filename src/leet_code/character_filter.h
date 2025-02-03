#pragma once

#include <string>

namespace leet_code
{

class TextInput
{
public:
    virtual void add(char c)
    {
	    value += c;
    }

    std::string getValue() const
    {
	    return value;
    }

protected:
    std::string value;
};

class NumericInput : public TextInput
{
public:
    void add(char c) override
    {
	    if (isdigit(c)) 
            value += c;
    }
};

}