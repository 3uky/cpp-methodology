// https://www.cplusplus.com/doc/tutorial/functions2/

#pragma once

using namespace std;

namespace basic_paradigm
{

class MyTemplate
{
    public:
        template <class T>
        static T sum (T a, T b) {
          return a+b;
        }
};

}