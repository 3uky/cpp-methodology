#include <iostream>
#include <string>
#include <utility>
#include <boost/asio.hpp>

#include "tcp_server_synchronous.h"

using namespace std;
using boost::asio::ip::tcp;

Server::Server() : m_acceptor(m_io_context, tcp::endpoint(tcp::v4(), 13)) 
{
    reply();
};    

void Server::run()
{
    m_io_context.run();
}

void Server::reply()
{
    for (;;)
    {
        tcp::socket m_socket(m_io_context);
        m_acceptor.accept(m_socket);
        string message = make_daytime_string();

        boost::system::error_code ignored_error;
        boost::asio::write(m_socket, boost::asio::buffer(message), ignored_error);
    }
}

string Server::make_daytime_string()
{
    time_t now = time(0);
    return ctime(&now);
}

