#include <utility>
#include <boost/asio.hpp>

#include "tcp_connection.h"

using boost::asio::ip::tcp;

tcp_connection::tcp_connection(boost::asio::io_context& io_context) : m_socket(io_context)
{
}

tcp::socket& tcp_connection::socket()
{
    return m_socket;
}

void tcp_connection::start()
{
    m_message = make_daytime_string();
    boost::asio::async_write(m_socket, boost::asio::buffer(m_message), std::bind(&tcp_connection::handle_write, shared_from_this()));
}

std::string tcp_connection::make_daytime_string()
{
    time_t now = time(0);
    return ctime(&now);
}

void tcp_connection::handle_write()
{

}