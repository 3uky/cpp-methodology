#ifndef T_BOOST_ASIO_H
#define T_BOOST_ASIO_H

#include <iostream>
#include <boost/asio.hpp>

class T_boost_asio
{
public:
    static void print(const boost::system::error_code& /*e*/) {
        std::cout << "Hello, world!" << std::endl;
    }

    static int test() {
        boost::asio::io_context io;

        boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));
        t.async_wait(&print);

        io.run();

        return 0;
    }
};

#endif // T_BOOST_ASIO_H
