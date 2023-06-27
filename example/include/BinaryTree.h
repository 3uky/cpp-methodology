#pragma once

#include<list>

// Time Complexity : O(N)
// Space Complexity: O(1)/O(n)

namespace algorithms
{

class Node
{
public:
    Node(int data) : m_data(data) {}

    int Get() const
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
    BinaryTree(int root_value) { SetRoot(root_value); }
    std::unique_ptr<Node> NewNode(int data)
    {
        return std::make_unique<Node>(data);
    }

    void GetPreOrder(const std::unique_ptr<Node>& node, std::list<int>& sequence)
    {
        if (node == nullptr)
            return;
        sequence.push_back(node->Get());
        GetPreOrder(node->left, sequence);
        GetPreOrder(node->right, sequence);
    }

    void GetInOrder(const std::unique_ptr<Node>& node, std::list<int>& sequence)
    {
        if (node == nullptr)
            return;
        GetInOrder(node->left, sequence);
    	sequence.push_back(node->Get());
        GetInOrder(node->right, sequence);
    }

    void GetPostOrder(const std::unique_ptr<Node>& node, std::list<int>& sequence)
    {
        if (node == nullptr)
            return;
        GetPostOrder(node->left, sequence);
        GetPostOrder(node->right, sequence);
    	sequence.push_back(node->Get());    
    }

    int GetHeight() const
    {
        return GetHeight(m_root);
    }

    int GetHeight(const std::unique_ptr<Node>& node) const
    {
        if (node == nullptr)
            return 0;
            
        int leftHeight = GetHeight(node->left);
        int rightHeight = GetHeight(node->left);
        
        return std::max(leftHeight, rightHeight) + 1;
    }

    const std::unique_ptr<Node>& GetRoot()
    {
        return m_root;
    }

    void SetRoot(int value)
    {
	    m_root = NewNode(1);
    }

private:
    std::unique_ptr<Node> m_root;
};

}