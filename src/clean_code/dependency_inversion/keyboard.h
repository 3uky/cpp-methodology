#pragma once

#include <iostream>

#include "i_reader.h"

namespace clean_code::solid
{

class Keyboard : public IReader
{

int Getchar() override
{
    int x;
    std::cin >> x;
    return x;
}

};

}