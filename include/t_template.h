// https://www.cplusplus.com/doc/tutorial/functions2/

#pragma once

using namespace std;

class T_template
{
    public:
        template <class T>
        static T sum (T a, T b) {
          return a+b;
        }

        static int test() {
          cout << sum (10, 20) << '\n';
          cout << sum (1.0, 1.5) << '\n';


          cout << sum<int>(10, 20);

          return 0;
        }
};