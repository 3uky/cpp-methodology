// https://learn.microsoft.com/en-us/windows/win32/winsock/complete-server-code

//#undef UNICODE

//#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>

namespace network {

class WinsockServer
{
public:
    WinsockServer();
    ~WinsockServer();

    void Listen(unsigned short serverPort = 27015);
    void Run();

private:
    void InitializeWinsock();
    void TerminateWinsock();
    addrinfo* ResolveServerAddressAndPort(unsigned short port);
    SOCKET CreateSocket(addrinfo* result);
    void BindSocket(SOCKET& listenSocket, addrinfo* serverInfo);
    void StartListening();
    SOCKET AcceptClient();
    void HandleConnection(SOCKET& clientSocket);
    void ShutdownConnection(SOCKET& clientSocket);
    void CloseSocket(SOCKET& socket);

    const unsigned short m_default_port = 27015;

    SOCKET m_listenSocket;
};

}