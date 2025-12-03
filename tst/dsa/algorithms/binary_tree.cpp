#include "gmock/gmock.h"

#include "binary_tree.h"

using ::testing::ElementsAre;

// time complexity:   O(n^2) best/worst case
// space complexity:  O(1)

using namespace std;

namespace algorithms
{
    TEST(BinaryTreeTest, ShouldReturnPreOrderSequence)
    {
        // GIVEN
        BinaryTree tree(std::vector<int>{1, 2, 3, 4, 5});

        // WHEN
        auto preorder_sequence = tree.GetPreOrder();

        // THEN
        EXPECT_THAT(preorder_sequence, ElementsAre(1, 2, 4, 5, 3));
    }

    TEST(BinaryTreeTest, ShouldReturnInOrderSequence)
    {
        // GIVEN
        BinaryTree tree(std::vector<int>{1, 2, 3, 4, 5});

        // WHEN
        auto inorder_sequence = tree.GetInOrder();

        // THEN
        EXPECT_THAT(inorder_sequence, ElementsAre(4, 2, 5, 1, 3));
    }

    TEST(BinaryTreeTest, ShouldReturnPostOrderSequence)
    {
        // GIVEN
        BinaryTree tree(std::vector<int>{1, 2, 3, 4, 5});

        // WHEN
        auto postorder_sequence = tree.GetPostOrder();
        
        // THEN
        EXPECT_THAT(postorder_sequence, ElementsAre(4, 5, 2, 3, 1));
    }

    TEST(BinaryTreeTest, ShouldReturnHeight)
    {
        // GIVEN
        BinaryTree tree_1(std::vector<int>{1, 2, 3});
        BinaryTree tree_2(std::vector<int>{1, 2, 3, 4, 5});

        // WHEN/THEN
    	EXPECT_THAT(tree_1.GetHeight(), 2);
        EXPECT_THAT(tree_2.GetHeight(), 3);
    }
}
