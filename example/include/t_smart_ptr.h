#pragma once

#include <iostream>
#include <memory>

class T_smart_ptr
{
    public:
        static int test()
        {
            //std::shared_ptr<int> p1 (new int);
            std::shared_ptr<int> p1 = std::make_shared<int>();
            *p1.get()=10;

            std::shared_ptr<int> p2 (p1);

            std::cout << "p2 points to " << *p2 << '\n';

            return 0;
        }
};