#include "gmock/gmock.h"

#include "Singleton.h"

using namespace std;

namespace design_patterns
{
    void PrintValue() {
        cout << "POINTER    main: global is " << SingletonPtr::instance()->GetValue() << endl;
        cout << "REFERENCE  main: global is " << SingletonRef::instance().GetValue() << endl;
        cout << "SHARED PTR main: global is " << SingletonShared::instance()->GetValue() << endl << endl;
        cout << "UNIQUE PTR main: global is " << SingletonUnique::instance()->GetValue() << endl << endl;
    };

    void SetValue(int val) {
        SingletonPtr::instance()->SetValue(val);
        SingletonRef::instance().SetValue(val);
        SingletonShared::instance()->SetValue(val);
        SingletonUnique::instance()->SetValue(val);
    };


    TEST(SignletonTest, ShouldSetValueThoughSingleton)
    {
        // GIVEN
        constexpr int expected_value_default = 0;
        constexpr int expected_value_1 = 1;
        constexpr int expected_value_2 = 2;

        EXPECT_EQ(SingletonPtr::instance()->GetValue(), expected_value_default);
        EXPECT_EQ(SingletonPtr::instance()->GetValue(), SingletonRef::instance().GetValue());
        EXPECT_EQ(SingletonPtr::instance()->GetValue(), SingletonShared::instance()->GetValue());
        
        SetValue(expected_value_1);
        EXPECT_EQ(SingletonPtr::instance()->GetValue(), expected_value_1);
        EXPECT_EQ(SingletonPtr::instance()->GetValue(), SingletonRef::instance().GetValue());
        EXPECT_EQ(SingletonPtr::instance()->GetValue(), SingletonShared::instance()->GetValue());
        
        SetValue(expected_value_2);
        EXPECT_EQ(SingletonPtr::instance()->GetValue(), expected_value_2);
        EXPECT_EQ(SingletonPtr::instance()->GetValue(), SingletonRef::instance().GetValue());
        EXPECT_EQ(SingletonPtr::instance()->GetValue(), SingletonShared::instance()->GetValue());
    };

    TEST(SignletonTest, ShouldReturnSameValuesThroughDifferentSingletonImplementations)
    {
        // GIVEN
        constexpr int expected_value = 1;

        // WHEN
        SetValue(expected_value);

        // THEN
        EXPECT_EQ(SingletonPtr::instance()->GetValue(), expected_value);
        EXPECT_EQ(SingletonRef::instance().GetValue(), expected_value);
        EXPECT_EQ(SingletonShared::instance()->GetValue(), expected_value);
        EXPECT_EQ(SingletonUnique::instance()->GetValue(), expected_value);
    };


}