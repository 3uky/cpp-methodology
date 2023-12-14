// https://learn.microsoft.com/en-us/windows/win32/winsock/complete-server-code

#include "WinsockServer.h"

#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>
#include <chrono>

#pragma warning(disable : 4996)

using namespace std;

namespace network {

WinsockServer::WinsockServer() : m_listenSocket(INVALID_SOCKET)
{
    InitializeWinsock();
}

WinsockServer::~WinsockServer()
{
    TerminateWinsock();
}

void WinsockServer::InitializeWinsock() // initiates use of the Winsock DLL
{
    WSADATA wsaData;

    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0)
    {
        cerr << "WSAStartup failed with error: " << result << endl;
        throw;
    }
}

void WinsockServer::TerminateWinsock()
{
    WSACleanup();
}

void WinsockServer::Run()
{
    Listen();

	SOCKET clientSocket = AcceptClient(m_listenSocket);
	closesocket(m_listenSocket); // no longer need server socket
    HandleConnection(clientSocket);
    closesocket(clientSocket);
}

void CloseSocket(SOCKET& socket)
{
    closesocket(socket);
}

void WinsockServer::Listen()
{
    addrinfo* serverInfo = ResolveServerAddressAndPort();
    m_listenSocket = CreateSocket(serverInfo);
    BindSocket(m_listenSocket, serverInfo);
    freeaddrinfo(serverInfo);
    StartListening(m_listenSocket);
}


addrinfo* WinsockServer::ResolveServerAddressAndPort()
{
    addrinfo hints;
    addrinfo* serverInfo = NULL;
            
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    // Resolve the server address and port
    int result = getaddrinfo(NULL, std::to_string(m_default_port).c_str(), &hints, &serverInfo);
    if (result != 0)
    {
        cerr << "getaddrinfo failed with error: " << result << endl;
        WSACleanup();
        throw;
    }
            
    return serverInfo;
}

SOCKET WinsockServer::CreateSocket(addrinfo* result)
{
    // Create a SOCKET for the server to listen for client connections.
    SOCKET listenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (listenSocket == INVALID_SOCKET) {
        cerr << "socket failed with error: " << WSAGetLastError() << endl;
        freeaddrinfo(result);
        WSACleanup();
        throw;
    }

    return listenSocket;
}

void WinsockServer::BindSocket(SOCKET& listenSocket, addrinfo* serverInfo)
{
    // Setup the TCP listening socket
    const int result = bind(listenSocket, serverInfo->ai_addr, (int)serverInfo->ai_addrlen);
    if (result == SOCKET_ERROR) {
        cerr << "bind failed with error: " << WSAGetLastError() << endl;
        freeaddrinfo(serverInfo);
        closesocket(listenSocket);
        WSACleanup();
        throw;
    }
}

void WinsockServer::StartListening(SOCKET& listenSocket)
{
    const int result = listen(listenSocket, SOMAXCONN);
    if (result == SOCKET_ERROR) {
        cerr << "listen failed with error: " << WSAGetLastError() << endl;
        closesocket(listenSocket);
        WSACleanup();
        throw;
    }
}

SOCKET WinsockServer::AcceptClient(SOCKET& listenSocket)
{
    // Accept a client socket
    SOCKET clientSocket = accept(listenSocket, NULL, NULL);
    if (clientSocket == INVALID_SOCKET) {
        cerr << "accept failed with error: " << WSAGetLastError() << endl;
        closesocket(listenSocket);
        WSACleanup();
        throw;
    }
    return clientSocket;
}

void WinsockServer::HandleConnection(SOCKET& clientSocket)
{
    int recvResult, sendResult;
            
    const int DEFAULT_BUFLEN = 512;
    char recvbuf[DEFAULT_BUFLEN];

    // Receive until the peer shuts down the connection
    do {
        recvResult = recv(clientSocket, recvbuf, DEFAULT_BUFLEN, 0);
        if (recvResult > 0) {
            
            cout << std::format("Server: Bytes received: {}", recvResult);

            //cout << "Server: Bytes received: " << recvResult << endl;

            // Echo the buffer back to the sender
            sendResult = send(clientSocket, recvbuf, recvResult, 0);
            if (sendResult == SOCKET_ERROR) {
                cout << "Server: send failed with error: " << WSAGetLastError() << endl;
                closesocket(clientSocket);
                WSACleanup();
                throw;
            }
            
            cout << std::format("Server: Bytes sent: {}", sendResult);
        }
        else if (recvResult == 0)
            cout << "Server: Connection closing..." << endl;
        else {
            cout << "Server: recv failed with error: " << WSAGetLastError() << endl;
            closesocket(clientSocket);
            WSACleanup();
            throw;
        }

    } while (recvResult > 0);

    ShutdownConnection(clientSocket);
}

void WinsockServer::ShutdownConnection(SOCKET& clientSocket)
{
    // shutdown the connection since we're done
    int result = shutdown(clientSocket, SD_SEND);
    if (result == SOCKET_ERROR) {
        cerr << "shutdown failed with error: " << WSAGetLastError() << endl;
        closesocket(clientSocket);
        WSACleanup();
        throw;
    }
}

}