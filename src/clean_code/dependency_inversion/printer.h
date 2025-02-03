#pragma once

#include <iostream>

#include "i_writer.h"

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