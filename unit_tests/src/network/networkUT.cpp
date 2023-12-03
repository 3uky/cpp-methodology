#include "gmock/gmock.h"

#include "WinsockServer.h"
#include "WinsockClient.h"

#include <thread>

using ::testing::ElementsAre;

namespace network
{

void ExecuteServer()
{
    WinsockServer s;
    s.Run();
}

void ExecuteClient()
{
    WinsockClient c;
    c.Run();
}

TEST(WinsockServerTest, DISABLED_ServerShouldRunAndListen)
{
    ExecuteServer();
}
TEST(WinsockServerTest, DISABLED_ServerShouldHandleClientRequest)
{
    std::thread serverThread { ExecuteServer };
    std::thread clientThread { ExecuteClient };
    serverThread.join();
    clientThread.join();
}

}