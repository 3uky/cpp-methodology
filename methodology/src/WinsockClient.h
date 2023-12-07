#define WIN32_LEAN_AND_MEAN


#include <winsock2.h>
#include <string>

namespace network
{

class WinsockClient
{
public:
    WinsockClient();
    ~WinsockClient();

    void ConnectToServer(const std::string& serverIp = "127.0.0.1", unsigned short serverPort = 27015);
    void SendToServer(const std::string& message);
    void CloseConnectionWithServer();

private:
    void InitializeWinsock();
    void TerminateWinsock();
    addrinfo* ResolveServerAddressAndPort(const std::string& serverIp, unsigned short serverPort);
    SOCKET CreateSocket(addrinfo* serverInfo);
    void ReceiveUntilPeerCloseConnection();
    void CloseSocket();
    void ShutdownConnection();

    SOCKET m_connectSocket;
};

}
