// https://www.boost.org/doc/libs/1_76_0/doc/html/boost_asio/tutorial/tuttimer2.html
// https://www.boost.org/doc/libs/1_76_0/doc/html/boost_asio/tutorial/tuttimer3.html
#ifndef T_BOOST_ASIO_H
#define T_BOOST_ASIO_H

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>

class T_boost_asio
{
public:
    static void print(const boost::system::error_code& /*e*/) {
        std::cout << "Hello, world!" << std::endl;
    }

    static int m_async_wait() {
        boost::asio::io_context io;

        boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));
        t.async_wait(boost::bind(print, boost::asio::placeholders::error));

        io.run();

        return 0;
    }


    static void print(const boost::system::error_code& /*e*/, boost::asio::steady_timer* t, int* count) {
        if (*count < 5) {
            std::cout << *count << std::endl;
            ++(*count);

            t->expires_at(t->expiry() + boost::asio::chrono::seconds(1));
            t->async_wait(boost::bind(print, boost::asio::placeholders::error, t, count));
        }
    }

    static void m_timer_3() {
        boost::asio::io_context io;

        int count = 0;
        boost::asio::steady_timer t(io, boost::asio::chrono::seconds(1));
        t.async_wait(boost::bind(print, boost::asio::placeholders::error, &t, &count));

        io.run();

        std::cout << "Final count is " << count << std::endl;
    }

    static void test() {
        //m_async_wait();
        m_timer_3();
    }
};

#endif // T_BOOST_ASIO_H
