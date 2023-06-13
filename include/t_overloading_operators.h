// https://www.cplusplus.com/doc/tutorial/templates/

#pragma once

#include <iostream>

using namespace std;

class CVector {
  public:
    int x,y;
    CVector () {};
    CVector (int a,int b) : x(a), y(b) {}
    CVector operator + (const CVector& param) {
        CVector temp;
        temp.x = x + param.x;
        temp.y = y + param.y;
        return temp;
    };
};

class T_overloading_operators
{
    public:
        static void test() {
            CVector foo (3,1);
            CVector bar (1,2);
            CVector result;
            result = foo + bar;
            cout << result.x << ',' << result.y << '\n';
        }
};
