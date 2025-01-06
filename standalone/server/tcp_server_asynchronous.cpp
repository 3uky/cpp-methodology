#include "tcp_server_asynchronous.h"

tcp_server::tcp_server() : m_acceptor(m_io_context, tcp::endpoint(tcp::v4(), 13))
{
    start_accept();
}

void tcp_server::run()
{
    m_io_context.run();
}

void tcp_server::start_accept()
{
    shared_ptr<tcp_connection> new_connection = std::make_shared<tcp_connection>(tcp_connection(m_io_context));

    m_acceptor.async_accept(new_connection->socket(), std::bind(&tcp_server::handle_accept, this, new_connection, std::placeholders::_1));
}

void tcp_server::handle_accept(shared_ptr<tcp_connection> new_connection, const boost::system::error_code& error)
{
    if (!error)
        new_connection->start();

    start_accept();
}