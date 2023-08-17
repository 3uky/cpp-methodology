#include "pch.h"
#include "AsyncWait.h"

namespace boost_asio
{

TEST(BoostAsioTest, DISABLED_ShouldAsyncWaitFiveTimesWithOneSecondInterval)
{
    boost::asio::io_context io;
    Printer p(io);
	io.run();
}

}

