#pragma once

// https://www.codeproject.com/Articles/1264257/Socket-Programming-in-Cplusplus-using-boost-asio-T
// https://www.boost.org/doc/libs/1_81_0/doc/html/boost_asio/tutorial/tutdaytime2.html

#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>
#include <boost/enable_shared_from_this.hpp>

using namespace boost::asio;
using namespace ip;
using namespace std; // For time_t, time and ctime;

class TcpConnection : public boost::enable_shared_from_this<TcpConnection>
{
public:
    typedef boost::shared_ptr<TcpConnection> pointer;

    static pointer Create(io_context& io_context)
    {
        return pointer(new TcpConnection(io_context));
    }

    tcp::socket& GetSocket()
    {
        return m_socket;
    }

    void Start()
    {
        async_write(m_socket, buffer("Hello, World!!"), bind(&TcpConnection::HandleWrite, shared_from_this()));
    }

private:
    TcpConnection(io_context& io_context) : m_socket(io_context) {}

    void HandleWrite()
    {
    }

    tcp::socket m_socket;
    std::string m_message;
};

class TCPServer
{
public:
    TCPServer(io_context& io_context) : m_io_context(io_context), m_acceptor(io_context, tcp::endpoint(tcp::v4(), 5555))
    {
        start_accept();
    }

private:
    void start_accept()
    {
        TcpConnection::pointer new_connection = TcpConnection::Create(m_io_context);
        m_acceptor.async_accept(new_connection->GetSocket(), boost::bind(&TCPServer::handle_accept, this, new_connection, std::placeholders::_1));
    }

    void handle_accept(TcpConnection::pointer new_connection, const boost::system::error_code& error)
    {
        if (!error)
        {
            new_connection->Start();
        }

        start_accept();
    }

    io_context& m_io_context;
    tcp::acceptor m_acceptor;
};


class TCPClient
{
public:
    TCPClient(std::string& ip_address, int port, io_context& context) : m_socket(context)
	{
        m_socket.connect(tcp::endpoint(address::from_string(ip_address), port));
    }

    std::string GetResponse() {
        boost::asio::streambuf buf;
        read_until(m_socket, buf, "\n");
        string data = boost::asio::buffer_cast<const char*>(buf.data());
        return data;
    }

private:
    tcp::socket m_socket;
};