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

    void Connect(const std::string& serverIp = "127.0.0.1", unsigned short serverPort = 27015);
    void Send(const std::string& message);
    std::string Receive();
    void CloseConnection();

private:
    void InitializeWinsock();
    void TerminateWinsock();
    addrinfo* ResolveServerAddressAndPort(const std::string& serverIp, unsigned short serverPort);
    SOCKET CreateSocket(addrinfo* serverInfo);
    void ReceiveUntilServerCloseConnection();
    void CloseSocket();
    void ShutdownConnection();

    SOCKET m_connectSocket;
};

}
