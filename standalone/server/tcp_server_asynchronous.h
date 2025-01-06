#include <utility>
#include <boost/asio.hpp>

#include "tcp_connection.h"

using namespace std;
using boost::asio::ip::tcp;

class tcp_server
{
public:
    tcp_server();
    void run();

private:
    void start_accept();   
    void handle_accept(shared_ptr<tcp_connection> new_connection, const boost::system::error_code& error);

    boost::asio::io_context m_io_context;
    boost::asio::ip::tcp::acceptor m_acceptor;
};