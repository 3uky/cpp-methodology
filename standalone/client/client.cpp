#include <array>
#include <iostream>
#include <utility>
#include <boost/asio.hpp>

#include "client.h"

using boost::asio::ip::tcp;
using namespace std;

Client::Client(string& hostname, string& service) : m_resolver(m_io_context), m_socket(m_io_context)
{
    resolve_and_connect(hostname, service);
}   

void Client::run()
{
    m_io_context.run();
}

void Client::resolve_and_connect(string& hostname, string& service)
{
    tcp::resolver::results_type endpoints = m_resolver.resolve(hostname, service);
    boost::asio::connect(m_socket, endpoints);
    read_data();
}

void Client::read_data()
{
    for (;;)
    {
        std::array<char, 128> buf;
        boost::system::error_code error;

        size_t len = m_socket.read_some(boost::asio::buffer(buf), error);
    
        if (error == boost::asio::error::eof)
            break; // Connection closed cleanly by peer.
        else if (error)
            throw boost::system::system_error(error); // Some other error.

        std::cout.write(buf.data(), len);
    }
}