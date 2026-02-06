#include "binary_tree_p.h"

namespace algorithms
{

BinaryTreeP::BinaryTreeP(std::vector<int>&& arr) 
{ 
    
}

void BinaryTreeP::GetPreOrder(NodeP* node, std::list<int>& sequence)
{
    if (node == nullptr)
        return;

    sequence.push_back(node->GetValue());
    GetPreOrder(node->left, sequence);
    GetPreOrder(node->right, sequence);
}

}