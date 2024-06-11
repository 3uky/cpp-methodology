// https://www.boost.org/doc/libs/1_76_0/doc/html/boost_asio/tutorial/tuttimer2.html
// https://www.boost.org/doc/libs/1_76_0/doc/html/boost_asio/tutorial/tuttimer3.html
// https://www.boost.org/doc/libs/1_76_0/doc/html/boost_asio/tutorial/tuttimer4.html

#pragma once

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>

namespace boost_asio
{

class Printer
{
public:
    Printer(boost::asio::io_context& io) : m_timer(io, boost::asio::chrono::seconds(1)), m_count(0)
    {
        m_timer.async_wait(boost::bind(&Printer::Print, this));
    }

    ~Printer() {
        std::cout << "Final count is " << m_count << std::endl;
    }

    void Print() {
        if (m_count < 5)
        {
            std::cout << m_count << std::endl;
            ++m_count;

            m_timer.expires_at(m_timer.expiry() + boost::asio::chrono::seconds(1));
            m_timer.async_wait(boost::bind(&Printer::Print, this));
        }
    }

private:
    boost::asio::steady_timer m_timer;
    int m_count;
};

}