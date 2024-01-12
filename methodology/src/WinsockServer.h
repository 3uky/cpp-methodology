// https://learn.microsoft.com/en-us/windows/win32/winsock/complete-server-code

#include <winsock2.h>
#include <string>
#include <functional>

namespace network {

class WinsockServer
{
public:
    WinsockServer();
    ~WinsockServer();

    void Listen(unsigned short serverPort = 27015);
    SOCKET AcceptClient();
    void ShutdownConnection(SOCKET& clientSocket);
    std::string Receive(SOCKET& clientSocket);
    void Send(const std::string& message, SOCKET& clientSocket);

    void DefineClientRequestHandler(std::function<void(std::string clientRequestMessage, SOCKET& clientSocket)> callback);
    void HandleClientRequests(SOCKET& clientSocket);

private:
    void InitializeWinsock();
    void TerminateWinsock();
    void SetDefaultClientRequestHandler();
    addrinfo* ResolveServerAddressAndPort(unsigned short port);
    SOCKET CreateSocket(addrinfo* result);
    void BindSocket(SOCKET& listenSocket, addrinfo* serverInfo);
    void StartListening();
    void CloseSocket(SOCKET& socket);

    const unsigned short m_default_port = 27015;
    SOCKET m_listenSocket;

    std::function<void(std::string message, SOCKET& socket)> m_clientRequestHandler;
};

}