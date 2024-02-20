#pragma once

#include <string>

namespace clean_code
{
    class IReportPrinter
    {
    public:
        virtual void Print(std::string print) = 0;
    };
}