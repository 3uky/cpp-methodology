#include "gmock/gmock.h"

#include "WinsockServer.h"

using ::testing::ElementsAre;

namespace network
{

TEST(WinsockServerTest, DISABLED_ShouldHandleClient)
{
    Server s;
    s.Run();
}

}