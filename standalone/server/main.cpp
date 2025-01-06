#include <string>
#include <iostream>

#include "tcp_server_synchronous.h"
#include "tcp_server_asynchronous.h"

int main()
{
    try
    {
        tcp_server server;
        server.run();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}