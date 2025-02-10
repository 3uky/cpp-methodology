#include <iostream>
#include <string>

#include "i_report_printer.h"

namespace clean_code::solid
{

class ReportPrinter : public IReportPrinter
{
public:
    void Print(std::string print) override
    {
        std::cout << print;
    }
};

}