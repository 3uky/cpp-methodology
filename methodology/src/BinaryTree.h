#pragma once

#include <list>
#include <memory>
#include <vector>

#include "BinaryTreeNode.h"

// Time Complexity : O(N)
// Space Complexity: O(1)/O(n)

namespace algorithms
{

class BinaryTree
{
public:
    BinaryTree();
    BinaryTree(std::vector<int>&& arr);

    std::list<int> GetPreOrder();
    std::list<int> GetInOrder();
    std::list<int> GetPostOrder();
    int GetHeight() const;

private:
    std::unique_ptr<Node> CreateNode(int data);
    void BuildInLevelOrder(const std::vector<int>& values);
    void GetPreOrder(const std::unique_ptr<Node>& node, std::list<int>& sequence);
    void GetInOrder(const std::unique_ptr<Node>& node, std::list<int>& sequence);
    void GetPostOrder(const std::unique_ptr<Node>& node, std::list<int>& sequence);
    int GetHeight(const std::unique_ptr<Node>& node) const;

    std::unique_ptr<Node> m_root;
};

}