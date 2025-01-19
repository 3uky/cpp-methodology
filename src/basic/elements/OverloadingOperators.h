// https://www.cplusplus.com/doc/tutorial/templates/

#pragma once

using namespace std;

namespace basic_elements
{

class ComplexNumber {

public:
    ComplexNumber() {}
    ComplexNumber(double r, double i) : _r(r), _i(i) {}

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

    ComplexNumber operator*(const ComplexNumber& param)
    {
        ComplexNumber temp;
        temp._r = _r * param._r - _i * param._i;
        temp._i = _r * param._i + _i * param._r;
        return temp;
    }

    ComplexNumber operator/(const ComplexNumber& param)
    {
        ComplexNumber temp;
        double denominator = param._r * param._r + param._i * param._i;
        temp._r = (_r * param._r + _i * param._i) / denominator;
        temp._i = (_i * param._r - _r * param._i) / denominator;
        return temp;
    }


    double getReal() const
    {
        return _r;
    }

    double getImaginary() const
    {
        return _i;
    }

private:
    double _r, _i;
};

}