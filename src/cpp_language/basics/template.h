// https://www.cplusplus.com/doc/tutorial/functions2/

#pragma once

namespace cpp_basic_constructs
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