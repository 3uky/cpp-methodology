#include "pch.h"
#include "BinaryTree.h"

using ::testing::ElementsAre;

// time complexity:   O(n^2) best/worst case
// space complexity:  O(1)

using namespace std;

namespace algorithms
{
    TEST(BinaryTreeTest, ShouldReturnPreOrderSequence)
    {
        // GIVEN
    	BinaryTree tree(1);
        const auto& root = tree.GetRoot();
        root->left = tree.NewNode(2);
        root->right = tree.NewNode(3);
        root->left->left = tree.NewNode(4);
        root->left->right = tree.NewNode(5);

        // WHEN
    	std::list<int> preorder_sequence;
        tree.GetPreOrder(root, preorder_sequence);

        // THEN
        EXPECT_THAT(preorder_sequence, ElementsAre(1, 2, 4, 5, 3));
    }

    TEST(BinaryTreeTest, ShouldReturnInOrderSequence)
    {
        // GIVEN
        BinaryTree tree(1);
        const auto& root = tree.GetRoot();
        root->left = tree.NewNode(2);
        root->right = tree.NewNode(3);
        root->left->left = tree.NewNode(4);
        root->left->right = tree.NewNode(5);

        // WHEN
        std::list<int> inorder_sequence;
        tree.GetInOrder(root, inorder_sequence);

        // THEN
        EXPECT_THAT(inorder_sequence, ElementsAre(4, 2, 5, 1, 3));
    }

    TEST(BinaryTreeTest, ShouldReturnPostOrderSequence)
    {
        // GIVEN
        BinaryTree tree(1);
        const auto& root = tree.GetRoot();
        root->left = tree.NewNode(2);
        root->right = tree.NewNode(3);
        root->left->left = tree.NewNode(4);
        root->left->right = tree.NewNode(5);

        // WHEN
        std::list<int> postorder_sequence;
        tree.GetPostOrder(root, postorder_sequence);

        // THEN
        EXPECT_THAT(postorder_sequence, ElementsAre(4, 5, 2, 3, 1));
    }

    TEST(BinaryTreeTest, ShouldReturnHeight)
    {
        // GIVEN
        BinaryTree tree(1);
        const auto& root = tree.GetRoot();
        root->left = tree.NewNode(2);
        root->right = tree.NewNode(3);

        // WHEN/THEN
    	EXPECT_THAT(tree.GetHeight(), 2);

        // GIVEN
        root->left->left = tree.NewNode(4);

        // WHEN/THEN
        EXPECT_THAT(tree.GetHeight(), 3);

        // GIVEN
        root->left->right = tree.NewNode(5);

        // WHEN/THEN
        EXPECT_THAT(tree.GetHeight(), 3);
    }
}
