// https://www.cplusplus.com/doc/tutorial/templates/

#pragma once

using namespace std;

namespace basic_elements
{

class ComplexNumber {

public:
    ComplexNumber() {}
    ComplexNumber(int r, int i) : _r(r), _i(i) {}

    ComplexNumber operator+(const ComplexNumber& param)
    {
        ComplexNumber temp;
        temp._r = _r + param._r;
        temp._i = _i + param._i;
        return temp;
    }

    ComplexNumber operator-(const ComplexNumber& param)
    {
        ComplexNumber temp;
        temp._r = _r - param._r;
        temp._i = _i - param._i;
        return temp;
    }

    int getReal() const
    {
        return _r;
    }
    int getImaginary() const
    {
        return _i;
    }

private:
    int _r, _i;
};

}