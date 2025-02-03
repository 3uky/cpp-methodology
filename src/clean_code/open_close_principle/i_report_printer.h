#include <string>

namespace clean_code::solid
{

class IReportPrinter
{
public:
    virtual void Print(std::string print) = 0;
};

}