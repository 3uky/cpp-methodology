#define WIN32_LEAN_AND_MEAN


#include <winsock2.h>
#include <string>

namespace network
{

class WinsockClient
{
public:
    void Run();
private:
    void InitializeWinsock();
    void TerminateWinsock();
    addrinfo* ResolveServerAddressAndPort();
    SOCKET CreateSocket(addrinfo* serverInfo);
    SOCKET ConnectToServer(addrinfo* allServerInfo);
    void SendInitialBuffer(SOCKET& connectSocket);
    void ShutdownConnection(SOCKET& connectSocket);
    void ReceiveUntilPeerCloseConnection(SOCKET& connectSocket);

    const unsigned short m_default_port = 27015;
    const std::string m_server_address = "127.0.0.1";
};

}
