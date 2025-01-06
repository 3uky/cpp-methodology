#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <utility>
#include <boost/asio.hpp>

class Client
{
public:
    Client(std::string& hostname, std::string& service);
    void run();
    void resolve_and_connect(std::string& hostnamem, std::string& service);
    void read_data();

private:
    boost::asio::io_context m_io_context;
    boost::asio::ip::tcp::resolver m_resolver;
    boost::asio::ip::tcp::socket m_socket;
};

#endif