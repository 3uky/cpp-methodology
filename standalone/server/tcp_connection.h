#ifndef TCP_CONNECTION_H
#define TCP_CONNECTION_H

#include <utility>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class tcp_connection : public std::enable_shared_from_this<tcp_connection>
{
public:
    tcp_connection(boost::asio::io_context& io_context);
   
    tcp::socket& socket();
    void start();

private:
    std::string make_daytime_string();
    void handle_write();

    tcp::socket m_socket;
    std::string m_message;
};

#endif