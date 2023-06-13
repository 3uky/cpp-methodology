#pragma once

#include <boost/signals2.hpp>

struct HelloWorld
{
    void operator()() const
    {
        std::cout << "Hello, World!" << std::endl;
    }
};

class T_boost_signal
{
    public:
        // Signal with no arguments and a void return value
        boost::signals2::signal<void ()> sig;

        void subscribe(std::function<void(void)> callback)
        {
            sig.connect(callback);
        }

        void trigger() {
            sig();
        }

        static void my_callback() {
            std::cout << "Hello, World from method!" << std::endl;
        }

        static void test() {
            T_boost_signal s;
            s.subscribe([](){std::cout << "Hello, World from lambda!" << std::endl;});
            s.subscribe(my_callback);
            s.trigger();
        }
};
