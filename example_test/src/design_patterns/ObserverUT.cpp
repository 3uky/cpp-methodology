#include "pch.h"
#include "observer.h"

using ::testing::_;
using ::testing::Return;

namespace design_patterns
{

class MockDivObserver : public DivObserver
{
public:
    MockDivObserver(int val) : DivObserver(val) { }

    MOCK_METHOD(void, OnNewValueEvent, (int value), (override));
};

TEST(AdapterTest, ShouldNotCallHandlerAfterObserverUnRegister) {
    Subject subject;

    MockDivObserver divObs1(4);

	EXPECT_CALL(divObs1, OnNewValueEvent(_)).Times(0);
    
	subject.Register(&divObs1);
    subject.UnRegister(&divObs1);

	subject.Notify(7);
}

TEST(AdapterTest, ShouldCallHandlerAfterObserverRegister) {
    Subject subject;

    MockDivObserver divObs1(4);

    EXPECT_CALL(divObs1, OnNewValueEvent(_)).Times(1);

    subject.Register(&divObs1);    

    subject.Notify(7);
}

TEST(AdapterTest, ShouldObserverReturnExpectedValueAfterNewValueEvent) {
    Subject subject;

    DivObserver divObs1(4);
    DivObserver divObs2(3);
    ModObserver modObs3(4);

    subject.Register(&divObs1);
    subject.Register(&divObs2);
    subject.Register(&modObs3);

    subject.Notify(7);

    EXPECT_EQ(divObs1.GetResult(), 1);
    EXPECT_EQ(divObs2.GetResult(), 2);
    EXPECT_EQ(modObs3.GetResult(), 3);
}

}