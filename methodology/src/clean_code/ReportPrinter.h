#pragma once

#include <iostream>
#include <string>

#include "IReportPrinter.h"

using namespace std;

namespace clean_code
{
    class ReportPrinter : public IReportPrinter
    {
    public:
        void Print(string print) override
        {
            cout << print;
        }
    };
}