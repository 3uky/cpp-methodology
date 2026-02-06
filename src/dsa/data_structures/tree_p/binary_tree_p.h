#pragma once

#include <list>
#include <memory>
#include <vector>

#include "binary_tree_node_p.h"

// Time Complexity : O(N)
// Space Complexity: O(1)/O(n)

namespace algorithms
{

class BinaryTreeP
{
public:
    BinaryTreeP();
    BinaryTreeP(NodeP* node) : m_root(node) {};
    BinaryTreeP(std::vector<int>&& arr);
/*
    std::list<int> GetPreOrder();
    std::list<int> GetInOrder();
    std::list<int> GetPostOrder();
    int GetHeight() const;*/
    void GetPreOrder(NodeP* node, std::list<int>& sequence);
private:
    
    //std::unique_ptr<NodeP> CreateNode(int data);
    //void BuildInLevelOrder(const std::vector<int>& values);
    /*void GetPreOrder(const std::unique_ptr<NodeP>& node, std::list<int>& sequence);
    void GetInOrder(const std::unique_ptr<NodeP>& node, std::list<int>& sequence);
    void GetPostOrder(const std::unique_ptr<NodeP>& node, std::list<int>& sequence);
    int GetHeight(const std::unique_ptr<NodeP>& node) const;*/

    NodeP* m_root;
};

}