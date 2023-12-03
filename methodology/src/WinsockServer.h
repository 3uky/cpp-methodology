// https://learn.microsoft.com/en-us/windows/win32/winsock/complete-server-code

#undef UNICODE

#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>

// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
// #pragma comment (lib, "Mswsock.lib")

namespace network {

class WinsockServer
{
public:
    void Run();

private:
    void InitializeWinsock(); // initiates use of the Winsock DLL by a process
    void TerminateWinsock();
    addrinfo* ResolveServerAddressAndPort();
    SOCKET CreateSocket(addrinfo* result);
    void BindSocket(SOCKET& ListenSocket, addrinfo* result);
    void StartListening(SOCKET& ListenSocket);
    SOCKET AcceptClient(SOCKET& ListenSocket);
    void HandleConnection(SOCKET& ClientSocket);
    void ShutdownConnection(SOCKET& ClientSocket);
};

}