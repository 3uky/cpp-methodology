#define WIN32_LEAN_AND_MEAN


#include <winsock2.h>

// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

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
    SOCKET CreateSocket(addrinfo* ptr);
    SOCKET ConnectToServer(addrinfo* serverInfo);
    void SendInitialBuffer(SOCKET& ConnectSocket);
    void ShutdownConnection(SOCKET& ConnectSocket);
    void ReceiveUntilPeerCloseConnection(SOCKET& ConnectSocket);
};

}
