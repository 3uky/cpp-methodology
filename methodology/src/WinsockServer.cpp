// https://learn.microsoft.com/en-us/windows/win32/winsock/complete-server-code

#include "WinsockServer.h"

#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>
#include <chrono>
#include <string>
#include <functional>
#include <iostream>
#pragma warning(disable : 4996)

using namespace std;

namespace network {

WinsockServer::WinsockServer() : m_listenSocket(INVALID_SOCKET)
{
    InitializeWinsock();
    SetDefaultClientRequestHandler();
}

// default handler reply with same message server received
void WinsockServer::SetDefaultClientRequestHandler()
{
    m_clientRequestHandler = [this](std::string clientRequestMessage, SOCKET& clientSocket) { Send(clientRequestMessage, clientSocket); };
}

void WinsockServer::DefineClientRequestHandler(std::function<void(std::string message, SOCKET& socket)> callback)
{
    m_clientRequestHandler = callback;
}

WinsockServer::~WinsockServer()
{
    CloseSocket(m_listenSocket);
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

void WinsockServer::CloseSocket(SOCKET& socket)
{
    if (socket != INVALID_SOCKET)
    {
        closesocket(socket);
        socket = INVALID_SOCKET;
    }
}

void WinsockServer::Listen(unsigned short serverPort)
{
    addrinfo* serverInfo = ResolveServerAddressAndPort(serverPort);
    m_listenSocket = CreateSocket(serverInfo);
    BindSocket(m_listenSocket, serverInfo);
    freeaddrinfo(serverInfo);
    StartListening();
}

addrinfo* WinsockServer::ResolveServerAddressAndPort(unsigned short port)
{
    addrinfo hints;
    addrinfo* serverInfo = NULL;
            
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    int result = getaddrinfo(NULL, std::to_string(port).c_str(), &hints, &serverInfo);
    if (result != 0)
    {
        cerr << "getaddrinfo failed with error: " << result << endl;
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
        throw;
    }

    return listenSocket;
}

void WinsockServer::BindSocket(SOCKET& listenSocket, addrinfo* serverInfo)
{
    // Setup the TCP listening socket
    const int result = ::bind(listenSocket, serverInfo->ai_addr, (int)serverInfo->ai_addrlen);
    if (result == SOCKET_ERROR) {
        cerr << "bind failed with error: " << WSAGetLastError() << endl;
        freeaddrinfo(serverInfo);
        throw;
    }
}

void WinsockServer::StartListening()
{
    const int result = listen(m_listenSocket, SOMAXCONN);
    if (result == SOCKET_ERROR) {
        cerr << "listen failed with error: " << WSAGetLastError() << endl;
        throw;
    }
}

SOCKET WinsockServer::AcceptClient()
{
    // Accept a client socket
    SOCKET clientSocket = accept(m_listenSocket, NULL, NULL);
    if (clientSocket == INVALID_SOCKET) {
        cerr << "accept failed with error: " << WSAGetLastError() << endl;
        throw;
    }
    return clientSocket;
}

void WinsockServer::HandleClientRequests(SOCKET& clientSocket)
{
    std::string message;

    while (message = Receive(clientSocket), !message.empty())
        m_clientRequestHandler(message, clientSocket);
}

std::string WinsockServer::Receive(SOCKET& clientSocket)
{
    const int DEFAULT_BUFLEN = 512;
    char recvbuf[DEFAULT_BUFLEN];

    int bytes = recv(clientSocket, recvbuf, DEFAULT_BUFLEN, 0);
    cout << std::format("Server: Bytes received: {}\n", bytes);
    
    if (bytes > 0)
    {
        return std::string(recvbuf, bytes);
    }
    if (bytes == 0)
        cout << "Server: Connection closing..." << endl;
    if (bytes < 0)
        cerr << "Server: recv failed with error: " << WSAGetLastError() << endl;
    
    return std::string{};
}

void WinsockServer::Send(const std::string& message, SOCKET& clientSocket)
{
    int result = send(clientSocket, message.c_str(), static_cast<int>(message.size()), 0);
    if (result == SOCKET_ERROR) {
        cerr << std::format("Server: send failed with error: {}\n", WSAGetLastError());
        CloseSocket(clientSocket);
        throw;
    }

    cout << std::format("Server: Bytes sent: {}", result);
}

void WinsockServer::ShutdownConnection(SOCKET& clientSocket)
{
    int result = shutdown(clientSocket, SD_SEND);
    if (result == SOCKET_ERROR) {
        cerr << "Server: shutdown failed with error: " << WSAGetLastError() << endl;
        CloseSocket(clientSocket);
        throw;
    }
}

}