// https://www.boost.org/doc/libs/1_76_0/doc/html/boost_asio/tutorial/tuttimer2.html
// https://www.boost.org/doc/libs/1_76_0/doc/html/boost_asio/tutorial/tuttimer3.html
// https://www.boost.org/doc/libs/1_76_0/doc/html/boost_asio/tutorial/tuttimer4.html

#ifndef T_BOOST_ASIO_H
#define T_BOOST_ASIO_H

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>

class printer
{
    boost::asio::steady_timer timer_;
    int count_;
public:
    printer(boost::asio::io_context& io) : timer_(io, boost::asio::chrono::seconds(1)), count_(0) {
        timer_.async_wait(boost::bind(&printer::print, this));
    }

    ~printer() {
        std::cout << "Final count is " << count_ << std::endl;
    }

    void print() {
        if (count_ < 5)
        {
            std::cout << count_ << std::endl;
            ++count_;

            timer_.expires_at(timer_.expiry() + boost::asio::chrono::seconds(1));
            timer_.async_wait(boost::bind(&printer::print, this));
        }
    }
};

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

    static void m_timer_4() {
        boost::asio::io_context io;
        printer p(io);
        io.run();
    }

    static void test() {
        //m_async_wait();
        //m_timer_3();
        m_timer_4();
    }
};

#endif // T_BOOST_ASIO_H
