#pragma once

#include <iostream>

#include "IWriter.h"

namespace clean_code::solid
{

class Printer : public IWriter
{
    void Putchar(int c) override
    {
        std::cout << static_cast<char>(c);
    }
};

}