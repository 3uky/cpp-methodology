#define WIN32_LEAN_AND_MEAN

#include "WinsockClient.h"

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>

// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

namespace network
{

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"

void WinsockClient::InitializeWinsock()
{
    WSADATA wsaData;

    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
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
    addrinfo* result;

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    // Resolve the server address and port
    int iResult = getaddrinfo("127.0.0.1", DEFAULT_PORT, &hints, &result);
    if (iResult != 0) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        throw;
    }
    return result;
}

SOCKET WinsockClient::CreateSocket(addrinfo* ptr)
{
    SOCKET ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
    if (ConnectSocket == INVALID_SOCKET) {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        WSACleanup();
        throw;
    }
    return ConnectSocket;
}

void WinsockClient::SendInitialBuffer(SOCKET& ConnectSocket)
{
    const char* sendbuf = "this is a test";

    int iResult = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);
    if (iResult == SOCKET_ERROR) {
        printf("send failed with error: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        throw;
    }

    printf("Bytes Sent: %ld\n", iResult);
}

void WinsockClient::ShutdownConnection(SOCKET& ConnectSocket)
{
    // shutdown the connection since no more data will be sent
    int iResult = shutdown(ConnectSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        throw;
    }
}

void WinsockClient::ReceiveUntilPeerCloseConnection(SOCKET& ConnectSocket)
{
    char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;
    int iResult;

    do {
        iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
        if (iResult > 0)
            printf("Bytes received: %d\n", iResult);
        else if (iResult == 0)
            printf("Connection closed\n");
        else
            printf("recv failed with error: %d\n", WSAGetLastError());

    } while (iResult > 0);
}

SOCKET WinsockClient::ConnectToServer(addrinfo* serverInfo)
{
    SOCKET connectSocket = INVALID_SOCKET;

    // Attempt to connect to an address until one succeeds
    for (addrinfo* ptr = serverInfo; ptr != NULL; ptr = ptr->ai_next) {
        connectSocket = CreateSocket(ptr);

        // Connect to server.
        int iResult = connect(connectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
        if (iResult == SOCKET_ERROR) {
            closesocket(connectSocket);
            connectSocket = INVALID_SOCKET;
            continue;
        }
        break;
    }

    if (connectSocket == INVALID_SOCKET) {
        printf("Unable to connect to server!\n");
        freeaddrinfo(serverInfo);
        WSACleanup();
        throw;
    }

    return connectSocket;
}

void WinsockClient::Run()
{
    InitializeWinsock();

    addrinfo* serverInfo = ResolveServerAddressAndPort();

    SOCKET connectSocket = ConnectToServer(serverInfo);

    freeaddrinfo(serverInfo);

    SendInitialBuffer(connectSocket);

    ShutdownConnection(connectSocket);

    ReceiveUntilPeerCloseConnection(connectSocket);

    closesocket(connectSocket);

    TerminateWinsock();
}

}
