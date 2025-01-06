#include "gmock/gmock.h"

#include "ObserverBoostSignal.h"

using namespace std;
using ::testing::Return;

namespace design_patterns
{

class MockObserver : public IObserver
{
public:
    MOCK_METHOD(std::string, Handler, (int eventValue), (override));
};


TEST(AdapterBoostSignalTest, ShouldExecuteRegisteredCallbackOnSignalTrigger)
{
    // GIVEN
    Subject subject;
    MockObserver observer;
    constexpr int eventValue = 1;

    // THEN
    EXPECT_CALL(observer, Handler(eventValue)).Times(1).WillOnce(Return(string()));

    // WHEN
    subject.Subscribe([&](int val) { return observer.Handler(val); });
    subject.Trigger(eventValue);
}

}


