#include "gmock/gmock.h"

#include "binary_tree_p.h"
#include <list>
using ::testing::ElementsAre;

// time complexity:   O(n^2) best/worst case
// space complexity:  O(1)

using namespace std;

namespace algorithms
{
    TEST(BinaryTreePTest, ShouldReturnPreOrderSequence)
    {
        // GIVEN
        NodeP* firstNode = new NodeP(1);
        NodeP* secondNode = new NodeP(2);
        NodeP* thirdNode = new NodeP(3);
        NodeP* fourthNode = new NodeP(4);
        NodeP* fifthNode = new NodeP(5);

        // Connect binary tree nodes
        firstNode->left = secondNode;
        firstNode->right = thirdNode;
        secondNode->left = fourthNode;
        secondNode->right = fifthNode;

        BinaryTreeP tree(firstNode);

        // WHEN
        std::list<int> preorder_sequence;
        tree.GetPreOrder(firstNode, preorder_sequence);

        // THEN
        EXPECT_THAT(preorder_sequence, ElementsAre(1, 2, 4, 5, 3));

        delete fourthNode;
        delete thirdNode;
        delete secondNode;
        delete firstNode;
        delete fifthNode;
    }
}
