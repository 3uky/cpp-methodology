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

TEST(ContainersListTest, ShouldPushNewValuesInForwardList)
{
    // GIVEN
    ForwardList<int> tested_list;

    // WHEN
    tested_list.Push(0);
    tested_list.Push(1);
    tested_list.Push(2);
    tested_list.Push(3);
    
    // THEN
    ASSERT_THAT(ForwardList2List<int>(tested_list), ElementsAre(3, 2, 1, 0));
}

TEST(ContainersListTest, ShouldPopValueFromForwardList)
{
    // GIVEN
    ForwardList<int> tested_list;

    tested_list.Push(0);
    tested_list.Push(1);
    tested_list.Push(2);
    tested_list.Push(3);

    // WHEN
    tested_list.Pop();

    // THEN
    ASSERT_THAT(ForwardList2List<int>(tested_list), ElementsAre(2, 1, 0));
}

TEST(ContainersListTest, ShouldHandlePopEmptyForwardList)
{
    // GIVEN
    ForwardList<int> tested_list;
  
    // WHEN
    tested_list.Pop();
    
    // THEN
    ASSERT_THAT(ForwardList2List<int>(tested_list), ElementsAre());
}

TEST(ContainersListTest, ShouldPopAllElementsFromForwardList)
{
    // GIVEN
    ForwardList<int> tested_list;

    tested_list.Push(0);
    tested_list.Push(1);
    tested_list.Push(2);
    tested_list.Push(3);

    // WHEN
    tested_list.Pop();
    tested_list.Pop();
    tested_list.Pop();
    tested_list.Pop();

    // THEN
    ASSERT_THAT(ForwardList2List<int>(tested_list), ElementsAre());
}

TEST(ContainersListTest, ShouldCleanForwardList)
{
    // GIVEN
    ForwardList<int> tested_list;

    tested_list.Push(0);
    tested_list.Push(1);
    tested_list.Push(2);
    tested_list.Push(3);

    // WHEN
    tested_list.Clean();

    // THEN
    ASSERT_THAT(ForwardList2List<int>(tested_list), ElementsAre());
}

TEST(ContainersListTest, DISABLED_ShouldBeAbleToHanldeLargeNumberOfValueInsertionIntoForwardList)
{
    // GIVEN/WHEN
    ForwardList<int> tested_list;


    // WHEN
    for (int i = 0; i < 10000000; i++)
        tested_list.Push(i);
    tested_list.Clean();   

    // THEN
    ASSERT_THAT(ForwardList2List<int>(tested_list), ElementsAre());
}

TEST(ContainersListTest, ShouldReverseForwardList)
{
    // GIVEN
    ForwardList<int> tested_list;
    
    tested_list.Push(0);
    tested_list.Push(1);
    tested_list.Push(2);
    tested_list.Push(3);

    // WHEN
    tested_list.Reverse();

    // THEN
    ASSERT_THAT(ForwardList2List<int>(tested_list), ElementsAre(0, 1, 2, 3));
}

TEST(ContainersListTest, ShouldCopyForwardList)
{
    // GIVEN
    ForwardList<int> tested_list;

    tested_list.Push(0);
    tested_list.Push(1);
    tested_list.Push(2);
    tested_list.Push(3);

    // WHEN
    ForwardList<int> copied_list(tested_list);

    // THEN
    ASSERT_THAT(ForwardList2List<int>(copied_list), ElementsAre(3, 2, 1, 0));
}

TEST(ContainersListTest, ShouldMoveForwardList)
{
    // GIVEN
    ForwardList<int> tested_list;

    tested_list.Push(0);
    tested_list.Push(1);
    tested_list.Push(2);
    tested_list.Push(3);

    // WHEN
    ForwardList<int> moved_list= std::move(tested_list);

    // THEN
    ASSERT_THAT(ForwardList2List<int>(moved_list), ElementsAre(3, 2, 1, 0));
}

}