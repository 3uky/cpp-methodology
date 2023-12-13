#include "WinsockClient.h"

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>
#include <chrono>
#include <format>

#pragma warning(disable : 4996)

using namespace std;

namespace network
{

WinsockClient::WinsockClient() : m_connectSocket(INVALID_SOCKET)
{
    InitializeWinsock();
}

void WinsockClient::InitializeWinsock()
{
    WSADATA wsaData;

    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0)
    {
        cerr << "WSAStartup failed with error: " << result << endl;
        throw;
    }
}

WinsockClient::~WinsockClient()
{
    TerminateWinsock();
}

void WinsockClient::TerminateWinsock()
{
    WSACleanup();
}

void WinsockClient::Connect(const std::string& serverIp, unsigned short serverPort)
{
    addrinfo* serverInfo = ResolveServerAddressAndPort(serverIp, serverPort);

	// Attempt to connect to an address until one succeeds
    for (serverInfo; serverInfo != nullptr; serverInfo = serverInfo->ai_next) {
        m_connectSocket = CreateSocket(serverInfo);

        int result = connect(m_connectSocket, serverInfo->ai_addr, static_cast<int>(serverInfo->ai_addrlen));
        if (result == SOCKET_ERROR) {
            CloseSocket();
            continue;
        }
        break;
    }

    freeaddrinfo(serverInfo);

    if (m_connectSocket == INVALID_SOCKET) {
        cerr << "Unable to connect to server!" << endl;
        throw;
    }
}

addrinfo* WinsockClient::ResolveServerAddressAndPort(const std::string& serverIp, unsigned short serverPort)
{
    addrinfo hints;
    addrinfo* serverInfo;

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    // Resolve the server address and port
    int result = getaddrinfo(serverIp.c_str(), to_string(serverPort).c_str(), &hints, &serverInfo);
    if (result != 0)
    {
        cerr << "getaddrinfo failed with error: " << result << endl;
        WSACleanup();
        throw;
    }
    return serverInfo;
}

SOCKET WinsockClient::CreateSocket(addrinfo* serverInfo)
{
    SOCKET ConnectSocket = socket(serverInfo->ai_family, serverInfo->ai_socktype, serverInfo->ai_protocol);
    if (ConnectSocket == INVALID_SOCKET) {
        cout << "socket failed with error: " << WSAGetLastError() << endl;
        WSACleanup();
        throw;
    }
    return ConnectSocket;
}

void WinsockClient::Send(const std::string& message)
{
    int result = send(m_connectSocket, message.c_str(), static_cast<int>(message.size()), 0);
    if (result == SOCKET_ERROR) {
        cerr << std::format("send failed with error: {}\n", WSAGetLastError());
        CloseSocket();
        TerminateWinsock();
        throw;
    }

	cout << std::format("Client: Bytes sent: {}", result);
}

void WinsockClient::CloseConnection()
{
    ShutdownConnection();
    ReceiveUntilServerCloseConnection();
    CloseSocket();
}

void WinsockClient::ShutdownConnection()
{
    // shutdown the connection since no more data will be sent
    int result = shutdown(m_connectSocket, SD_SEND);
    if (result == SOCKET_ERROR) {
        cerr << "shutdown failed with error: " << WSAGetLastError() << endl;
        closesocket(m_connectSocket);
        WSACleanup();
        throw;
    }
}

std::string WinsockClient::Receive()
{
    const int DEFAULT_BUFLEN = 512;
    char recvbuf[DEFAULT_BUFLEN];
    std::string receivedMessage;

    int bytes = recv(m_connectSocket, recvbuf, DEFAULT_BUFLEN, 0);

    if (bytes > 0)
        receivedMessage = std::string(recvbuf, bytes);
    if (bytes < 0)
        cerr << "Client: recv failed with error: " << WSAGetLastError() << endl;

	return receivedMessage;	// on close connection result would be 0 size string
}

void WinsockClient::ReceiveUntilServerCloseConnection()
{
    std::string receivedMessage;

    do
    {
        receivedMessage = Receive();
    } while (receivedMessage.size() != 0);

}

void WinsockClient::CloseSocket()
{
    if (m_connectSocket != INVALID_SOCKET)
    {
        closesocket(m_connectSocket);
        m_connectSocket = INVALID_SOCKET;
    }
}

}