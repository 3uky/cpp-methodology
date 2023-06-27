#pragma once

#include <list>
#include <queue>

// Time Complexity : O(N)
// Space Complexity: O(1)/O(n)

namespace algorithms
{

class Node
{
public:
    Node(int data) : m_data(data) {}

    int Value() const
    {
        return m_data;
    }

    std::unique_ptr<Node> left = nullptr;
    std::unique_ptr<Node> right = nullptr;

private:
    int m_data;
};

class BinaryTree
{
public:
    BinaryTree() {}
    BinaryTree(std::vector<int>& arr) { BuildInLevelOrder(arr); }

    std::list<int> GetPreOrder()
    {
        std::list<int> sequence;
        GetPreOrder(m_root, sequence);
        return sequence;
    }

    std::list<int> GetInOrder()
    {
        std::list<int> sequence;
        GetInOrder(m_root, sequence);
        return sequence;
    }

    std::list<int> GetPostOrder()
    {
        std::list<int> sequence;
        GetPostOrder(m_root, sequence);
        return sequence;
    }

    int GetHeight() const
    {
        return GetHeight(m_root);
    }

private:
    std::unique_ptr<Node> NewNode(int data)
    {
        return std::make_unique<Node>(data);
    }

    void BuildInLevelOrder(std::vector<int> arr)
    {
        std::queue<Node*> q;
        for (auto value : arr)
        {
            auto node = NewNode(value);

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

    void GetPreOrder(const std::unique_ptr<Node>& node, std::list<int>& sequence)
    {
        if (node == nullptr)
            return;

        sequence.push_back(node->Value());
        GetPreOrder(node->left, sequence);
        GetPreOrder(node->right, sequence);
    }

    void GetInOrder(const std::unique_ptr<Node>& node, std::list<int>& sequence)
    {
        if (node == nullptr)
            return;

        GetInOrder(node->left, sequence);
        sequence.push_back(node->Value());
        GetInOrder(node->right, sequence);
    }

    void GetPostOrder(const std::unique_ptr<Node>& node, std::list<int>& sequence)
    {
        if (node == nullptr)
            return;

        GetPostOrder(node->left, sequence);
        GetPostOrder(node->right, sequence);
        sequence.push_back(node->Value());
    }

    int GetHeight(const std::unique_ptr<Node>& node) const
    {
        if (node == nullptr)
            return 0;

        int leftHeight = GetHeight(node->left);
        int rightHeight = GetHeight(node->left);

        return std::max(leftHeight, rightHeight) + 1;
    }

    std::unique_ptr<Node> m_root;
};

}