// https://learn.microsoft.com/en-us/windows/win32/winsock/complete-server-code

#include <winsock2.h>
#include <string>

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
    std::string Receive(SOCKET& clientSocket);
    void Send(const std::string& message, SOCKET& clientSocket);
	void ShutdownConnection(SOCKET& clientSocket);
    void CloseSocket(SOCKET& socket);

    const unsigned short m_default_port = 27015;
    SOCKET m_listenSocket;
};

}