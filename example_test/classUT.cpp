#include "pch.h"
#include "class.h"

namespace basic_paradigm
{
    TEST(ClassTest, ShouldBeInitializedStaticaly) {
        // GIVEN        
        TestClass myClass(10);
        
        // THEN
        EXPECT_EQ(myClass.get(), 10);
    }

    TEST(ClassTest, ShouldBeInitializedDynamicaly) {
        // GIVEN        
        TestClass *foo, *bar;
        
        // WHEN
        foo = new TestClass(10);
        bar = new TestClass[2]{ {*foo}, {20} };

        // THEN
        EXPECT_EQ(foo->get(), 10);
        EXPECT_EQ(bar[0].get(), 10);
        EXPECT_EQ(bar[1].get(), 20);


        // CLEANUP
        delete foo;
        delete[] bar;
    }

    TEST(ClassTest, ShouldBeAccessedThroughPointer) {
        // GIVEN        
        TestClass obj(10);
        TestClass *pobj;

        // WHEN
        pobj = &obj;

        // THEN
        EXPECT_EQ(obj.get(), pobj->get());
    }

    TEST(ClassTest, ShouldBeDestructedInOrder) {
        Child obj;
    }
}
