#include <iostream>

#include "client.h"

int main(int argc, char* argv[])
{
    try
    {
        if (argc != 2)
        {
            std::cerr << "Usage: client <host>" << std::endl;
            return 1;
        }
        std::string hostname = argv[1];
        std::string service{"daytime"};
        Client client(hostname, service);
        client.run();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}