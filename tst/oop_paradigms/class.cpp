#include "gmock/gmock.h"

#include "my_class.h"

namespace oop_paradigm
{
    
TEST(ClassTest, ShouldBeInitializedStaticaly)
{
    // GIVEN        
    MyClass myClass(10);
    
    // THEN
    EXPECT_EQ(myClass.get(), 10);
}

TEST(ClassTest, ShouldBeInitializedDynamicaly)
{
    // GIVEN        
    MyClass*foo, *bar;
    
    // WHEN
    foo = new MyClass(10);
    bar = new MyClass[2]{ {*foo}, {20} };

    // THEN
    EXPECT_EQ(foo->get(), 10);
    EXPECT_EQ(bar[0].get(), 10);
    EXPECT_EQ(bar[1].get(), 20);


    // CLEANUP
    delete foo;
    delete[] bar;
}

TEST(ClassTest, ShouldBeAccessedThroughPointer)
{
    // GIVEN        
    MyClass obj(10);
    MyClass *pobj;

    // WHEN
    pobj = &obj;

    // THEN
    EXPECT_EQ(obj.get(), pobj->get());
}

TEST(ClassTest, ShouldBeDestructedInOrder)
{
    Child obj;
}

}