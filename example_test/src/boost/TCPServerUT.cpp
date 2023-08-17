#include "pch.h"
#include "TCPServer.h"

using namespace std;

namespace boost_asio
{
    // nc 127.0.0.1 5555
    // ncat 127.0.0.1 5555
	TEST(NetworkTest, DISABLED_TCPServerShouldHandleClientRequest)
	{
        try
        {
            std::string ip = "127.0.0.1";
            io_context io_context;
            TCPServer server(io_context);
            
            io_context.run();
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

}