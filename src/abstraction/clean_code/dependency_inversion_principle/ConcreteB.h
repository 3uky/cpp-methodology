#pragma once

#include "Interface.h"
#include <iostream>

class ConcreteB : public Interface
{
public:
    void DoSomething() override
    {
        std::cout << "Subclass B doing something..."  << std::endl;
    }
};