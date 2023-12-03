#include "WinsockClient.h"
#include "WinsockLogger.h"

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <chrono>
#include <format>

#pragma warning(disable : 4996)

using namespace std;

namespace network
{

void WinsockClient::InitializeWinsock()
{
    WSADATA wsaData;

    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        cerr << "WSAStartup failed with error: " << result << endl;
        throw;
    }
}

void WinsockClient::TerminateWinsock()
{
    WSACleanup();
}

addrinfo* WinsockClient::ResolveServerAddressAndPort()
{
    addrinfo hints;
    addrinfo* serverInfo;

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    // Resolve the server address and port
    int result = getaddrinfo(m_server_address.c_str(), to_string(m_default_port).c_str(), &hints, &serverInfo);
    if (result != 0) {
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

void WinsockClient::SendInitialBuffer(SOCKET& connectSocket)
{
    const char* sendbuf = "this is a test";

    int result = send(connectSocket, sendbuf, (int)strlen(sendbuf), 0);
    if (result == SOCKET_ERROR) {
        printf("send failed with error: %d\n", WSAGetLastError());
        closesocket(connectSocket);
        WSACleanup();
        throw;
    }

    WinsockLogger::Log(std::format("Client: Bytes sent: {}", result));
}

void WinsockClient::ShutdownConnection(SOCKET& connectSocket)
{
    // shutdown the connection since no more data will be sent
    int result = shutdown(connectSocket, SD_SEND);
    if (result == SOCKET_ERROR) {
        cerr << "shutdown failed with error: " << WSAGetLastError() << endl;
        closesocket(connectSocket);
        WSACleanup();
        throw;
    }
}

void WinsockClient::ReceiveUntilPeerCloseConnection(SOCKET& connectSocket)
{
    const int DEFAULT_BUFLEN = 512;
    char recvbuf[DEFAULT_BUFLEN];
    int result;

    do {
        result = recv(connectSocket, recvbuf, DEFAULT_BUFLEN, 0);
        if (result > 0)
            WinsockLogger::Log(format("Client: Bytes received: {}", result));
			
        else if (result == 0)
            cout << "Client: Connection closed" << endl;
        else
            cout << "Client: recv failed with error: " << WSAGetLastError() << endl;

    } while (result > 0);
}

SOCKET WinsockClient::ConnectToServer(addrinfo* allServerInfo)
{
    SOCKET connectSocket = INVALID_SOCKET;

    // Attempt to connect to an address until one succeeds
    for (addrinfo* serverInfo = allServerInfo; serverInfo != NULL; serverInfo = serverInfo->ai_next) {
        connectSocket = CreateSocket(serverInfo);

        int result = connect(connectSocket, serverInfo->ai_addr, static_cast<int>(serverInfo->ai_addrlen));
        if (result == SOCKET_ERROR) {
            closesocket(connectSocket);
            connectSocket = INVALID_SOCKET;
            continue;
        }
        break;
    }

    if (connectSocket == INVALID_SOCKET) {
        cerr << "Unable to connect to server!" << endl;
        freeaddrinfo(allServerInfo);
        WSACleanup();
        throw;
    }

    return connectSocket;
}

void WinsockClient::Run()
{
    InitializeWinsock();

    addrinfo* allServerInfo = ResolveServerAddressAndPort();
    SOCKET connectSocket = ConnectToServer(allServerInfo);
    freeaddrinfo(allServerInfo);

	SendInitialBuffer(connectSocket);
    ShutdownConnection(connectSocket);
    ReceiveUntilPeerCloseConnection(connectSocket);
    closesocket(connectSocket);

    TerminateWinsock();
}

}
