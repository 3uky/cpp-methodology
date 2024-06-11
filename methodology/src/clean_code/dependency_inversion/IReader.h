#pragma once

namespace clean_code::solid
{

class IReader
{
public:
    virtual int Getchar() = 0;
};

}