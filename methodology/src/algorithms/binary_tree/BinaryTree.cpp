#include "BinaryTree.h"

#include <list>
#include <queue>
#include <memory>

namespace algorithms
{

BinaryTree::BinaryTree()
{
}

BinaryTree::BinaryTree(std::vector<int>&& arr) 
{ 
    BuildInLevelOrder(arr); 
}

std::list<int> BinaryTree::GetPreOrder()
{
    std::list<int> sequence;
    GetPreOrder(m_root, sequence);
    return sequence;
}

std::list<int> BinaryTree::GetInOrder()
{
    std::list<int> sequence;
    GetInOrder(m_root, sequence);
    return sequence;
}

std::list<int> BinaryTree::GetPostOrder()
{
    std::list<int> sequence;
    GetPostOrder(m_root, sequence);
    return sequence;
}

int BinaryTree::GetHeight() const
{
    return GetHeight(m_root);
}

std::unique_ptr<Node> BinaryTree::CreateNode(int data)
{
    return std::make_unique<Node>(data);
}

void BinaryTree::BuildInLevelOrder(const std::vector<int>& values)
{
    std::queue<Node*> q;
    for (auto value : values)
    {
        auto node = CreateNode(value);
            
        q.push(node.get());

        if (m_root == nullptr)
            m_root = std::move(node);
        else if (q.front()->left == nullptr)
            q.front()->left = std::move(node);
        else
        {
            q.front()->right = std::move(node);
            q.pop();
        }
    }
}

void BinaryTree::GetPreOrder(const std::unique_ptr<Node>& node, std::list<int>& sequence)
{
    if (node == nullptr)
        return;

    sequence.push_back(node->GetValue());
    GetPreOrder(node->left, sequence);
    GetPreOrder(node->right, sequence);
}

void BinaryTree::GetInOrder(const std::unique_ptr<Node>& node, std::list<int>& sequence)
{
    if (node == nullptr)
        return;

    GetInOrder(node->left, sequence);
    sequence.push_back(node->GetValue());
    GetInOrder(node->right, sequence);
}

void BinaryTree::GetPostOrder(const std::unique_ptr<Node>& node, std::list<int>& sequence)
{
    if (node == nullptr)
        return;

    GetPostOrder(node->left, sequence);
    GetPostOrder(node->right, sequence);
    sequence.push_back(node->GetValue());
}

int BinaryTree::GetHeight(const std::unique_ptr<Node>& node) const
{
    if (node == nullptr)
        return 0;

    int leftHeight = GetHeight(node->left);
    int rightHeight = GetHeight(node->right);

    return std::max(leftHeight, rightHeight) + 1;
}

}