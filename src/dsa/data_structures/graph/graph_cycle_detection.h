#include <iostream>
#include <vector>
#include <memory>
#include <unordered_set>

struct Node 
{
    std::vector<Node*> children;
};

bool dfs(Node* node, std::unordered_set<Node*>& visiting, std::unordered_set<Node*>& visited) 
{
    if (!node) 
        return false;
    if (visiting.count(node)) 
        return true;
    if (visited.count(node)) 
        return false;

    visiting.insert(node);

    for (auto child : node->children) 
    {
        if (dfs(child, visiting, visited))
            return true;
    }

    visiting.erase(node);
    visited.insert(node);
    
    return false;
}

bool has_cycle(Node* root) 
{
    std::unordered_set<Node*> visiting;
    std::unordered_set<Node*> visited;
    return dfs(root, visiting, visited);
}