#pragma once

namespace clean_code::solid
{

class IWriter
{
public:
    virtual void Putchar(int c) = 0;
};

}