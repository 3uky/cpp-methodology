// https://learn.microsoft.com/en-us/windows/win32/winsock/complete-server-code

//#undef UNICODE

//#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>

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
    void BindSocket(SOCKET& listenSocket, addrinfo* serverInfo);
    void StartListening(SOCKET& listenSocket);
    SOCKET AcceptClient(SOCKET& listenSocket);
    void HandleConnection(SOCKET& clientSocket);
    void ShutdownConnection(SOCKET& clientSocket);

    const unsigned short m_default_port = 27015;
};

}