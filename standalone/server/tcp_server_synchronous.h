#include <string>
#include <utility>
#include <boost/asio.hpp>

class Server
{
public:
        Server();
        void run();
        void reply();
        std::string make_daytime_string();

        boost::asio::io_context m_io_context;
        boost::asio::ip::tcp::acceptor m_acceptor;
};