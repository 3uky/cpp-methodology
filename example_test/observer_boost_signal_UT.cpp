#include "pch.h"
#include "observer_boost_signal.h"

using namespace std;
using ::testing::Return;

namespace design_patterns
{

class MockObserver : public IObserver
{
public:
    MOCK_METHOD(std::string, Handler, (), (override));
};


TEST(AdapterBoostSignalTest, ShouldExecuteRegisteredCallbackOnSignalTrigger)
{
    // GIVEN
    Subject subject;
    MockObserver observer;

    // THEN
    EXPECT_CALL(observer, Handler()).Times(1).WillOnce(Return(string("Hello, World!")));

    // WHEN
    subject.Subscribe([&]() { return observer.Handler(); });
    subject.Trigger();
}

}


