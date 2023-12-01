// https://learn.microsoft.com/en-us/windows/win32/winsock/complete-server-code

#undef UNICODE

#define WIN32_LEAN_AND_MEAN

#include "WinsockServer.h"

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>

// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
// #pragma comment (lib, "Mswsock.lib")

namespace network {

#define DEFAULT_PORT "27015"

void Server::Run()
{
    InitializeWinsock();

    addrinfo* result = ResolveServerAddressAndPort();

    SOCKET ListenSocket = CreateSocket(result);

    BindSocket(ListenSocket, result);

    freeaddrinfo(result);
            
    StartListening(ListenSocket);

    SOCKET ClientSocket = AcceptClient(ListenSocket);
          
    closesocket(ListenSocket); // No longer need server socket

    HandleConnection(ClientSocket);

    closesocket(ClientSocket);
    
    TerminateWinsock();
}

void Server::InitializeWinsock() // initiates use of the Winsock DLL by a process
{
    WSADATA wsaData;
    int iResult;

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0)
    {
        printf("WSAStartup failed with error: %d\n", iResult);
        throw;
    }
}

void Server::TerminateWinsock()
{
    WSACleanup();
}

addrinfo* Server::ResolveServerAddressAndPort()
{
    int iResult;
    addrinfo hints;
    addrinfo* result = NULL;
            
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    // Resolve the server address and port
    iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
    if (iResult != 0)
    {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        throw;
    }
            
    return result;
}

SOCKET Server::CreateSocket(addrinfo* result)
{
    SOCKET ListenSocket = INVALID_SOCKET;

    // Create a SOCKET for the server to listen for client connections.
    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ListenSocket == INVALID_SOCKET) {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        throw;
    }

    return ListenSocket;
}

void Server::BindSocket(SOCKET& ListenSocket, addrinfo* result)
{
    // Setup the TCP listening socket
    int iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
        throw;
    }
}

void Server::StartListening(SOCKET& ListenSocket)
{
    int iResult = listen(ListenSocket, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        printf("listen failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        throw;
    }
}

SOCKET Server::AcceptClient(SOCKET& ListenSocket)
{
    SOCKET ClientSocket = INVALID_SOCKET;

    // Accept a client socket
    ClientSocket = accept(ListenSocket, NULL, NULL);
    if (ClientSocket == INVALID_SOCKET) {
        printf("accept failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        throw;
    }
    return ClientSocket;
}

void Server::HandleConnection(SOCKET& ClientSocket)
{
    int iResult, iSendResult;
            
    const int DEFAULT_BUFLEN = 512;
    char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;

    // Receive until the peer shuts down the connection
    do {
        iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
        if (iResult > 0) {
            printf("Bytes received: %d\n", iResult);

            // Echo the buffer back to the sender
            iSendResult = send(ClientSocket, recvbuf, iResult, 0);
            if (iSendResult == SOCKET_ERROR) {
                printf("send failed with error: %d\n", WSAGetLastError());
                closesocket(ClientSocket);
                WSACleanup();
                throw;
            }
            printf("Bytes sent: %d\n", iSendResult);
        }
        else if (iResult == 0)
            printf("Connection closing...\n");
        else {
            printf("recv failed with error: %d\n", WSAGetLastError());
            closesocket(ClientSocket);
            WSACleanup();
            throw;
        }

    } while (iResult > 0);

    ShutdownConnection(ClientSocket);
}

void Server::ShutdownConnection(SOCKET& ClientSocket)
{
    // shutdown the connection since we're done
    int iResult = shutdown(ClientSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(ClientSocket);
        WSACleanup();
        throw;
    }
}



}