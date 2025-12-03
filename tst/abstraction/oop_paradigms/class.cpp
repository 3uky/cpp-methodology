#include "gmock/gmock.h"

#include "person.h"

namespace oop_paradigm
{

TEST(ClassTest, StaticObjectCreation) 
{
    Person p1("Alice");  // static instantiation (on the stack)

    EXPECT_EQ(p1.getName(), "Alice");
}

TEST(ClassTest, DynamicObjectCreation) 
{
    Person* p2 = new Person("Bob");  // dynamic instantiation (on the heap)

    EXPECT_EQ(p2->getName(), "Bob");

    delete p2;
}

TEST(ClassTest, DynamicObjectWithSmartPointer) 
{
    std::unique_ptr<Person> p3 = std::make_unique<Person>("Charlie");

    EXPECT_EQ(p3->getName(), "Charlie");

    // no need to manually delete, smart pointer will automatically clean up
}

}