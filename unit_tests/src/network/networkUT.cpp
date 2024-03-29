#include "gmock/gmock.h"

#include "WinsockServer.h"
#include "WinsockClient.h"

#include <thread>

using ::testing::ElementsAre;

namespace network
{

void ExecuteServer()
{
    WinsockServer server;
	server.Listen();
	auto clientSocket = server.AcceptClient();
	//server.DefineClientRequestHandler([&](std::string message, SOCKET& socket) {server.Send(message, socket); });
	server.HandleClientRequests(clientSocket);
    server.ShutdownConnection(clientSocket);
}

void ExecuteClient()
{
    WinsockClient client;
    client.Connect();
    client.Send("this is a test");
    auto message = client.Receive();
    client.CloseConnection();
}

TEST(WinsockServerTest, DISABLED_ServerShouldRunAndListen) // test: nc 127.0.0.1 27015
{
    ExecuteServer();
}
TEST(WinsockServerTest, DISABLED_ServerAndClientShouldFollowCommunicationProtocol)
{
    std::thread serverThread { ExecuteServer };
    std::thread clientThread { ExecuteClient };

	serverThread.join();
    clientThread.join();
}

TEST(WinsockServerTest, DISABLED_ServerShouldReplyToClientRequest)
{
    // GIVEN
    WinsockClient client;
	std::thread serverThread { ExecuteServer };
    std::string sendMessage = "Hello, World!";
    std::string expectedMessage = sendMessage; // server reply with same message as he received from client
    
    // WHEN
    client.Connect();
    client.Send(sendMessage);
    const auto receivedMessage = client.Receive();
    client.CloseConnection();

	serverThread.join();

    // THEN
    ASSERT_EQ(receivedMessage, expectedMessage);
}

}