#include "gmock/gmock.h"

#include "ForwardList.h"

using ::testing::ElementsAre;

namespace containers
{

template <typename T>
std::list<T> ForwardList2List(ForwardList<T>& list)
{
    std::list<T> linearizedList;

    Node<T>* head = list.Head();  
    while (head) 
    {
        T value = head->GetValue();
        head = head->Next();
        linearizedList.push_back(value);
    }

    return linearizedList;
}

TEST(ContainersListTest, ShouldInitializeForwardList)
{
    // GIVEN/WHEN
    ForwardList<int> tested_list;

    tested_list.Push(0);
    tested_list.Push(1);
    tested_list.Push(2);
    tested_list.Push(3);

    
    // THEN
    auto const linearizedTestedList = ForwardList2List<int>(tested_list);
    ASSERT_THAT(linearizedTestedList, ElementsAre(3, 2, 1, 0));
}

}