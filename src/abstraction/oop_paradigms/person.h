#pragma once

#include <iostream>
#include <string>

namespace oop_paradigm
{

class Person 
{
public:
    Person(const std::string& name) : name(name) {}

    std::string getName() const {
        return name;
    }

private:
    std::string name;
};

}