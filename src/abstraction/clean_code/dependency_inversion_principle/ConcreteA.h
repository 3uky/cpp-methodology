#pragma once

#include "Interface.h"
#include <iostream>

class ConcreteA : public Interface
{
public:
    void DoSomething() override
    {
        std::cout << "Subclass A doing something..."  << std::endl;
    }
};