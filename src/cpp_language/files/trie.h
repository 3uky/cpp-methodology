#include <unordered_map>
#include <string>

class TrieNode 
{
public:
    TrieNode() 
    {
        isEndOfWord = false;
    } 
    
    bool isEndOfWord;
    std::unordered_map<char, TrieNode*> children;
};  

void insert(TrieNode* root, const std::string &word) 
{
    TrieNode* node = root;
    for(char c : word) 
    {
        if(node->children.find(c) == node->children.end())
            node->children[c] = new TrieNode();
        node = node->children[c];
    }
    node->isEndOfWord = true;
}

bool search(TrieNode* root, const std::string &word) 
{
    TrieNode* node = root;
    for(char c : word) 
    {
        if(node->children.find(c) == node->children.end())
            return false;
        node = node->children[c];
    }
    return node->isEndOfWord;
}

bool startsWith(TrieNode* root, const std::string &prefix) 
{
    TrieNode* node = root;
    for(char c : prefix) 
    {
        if(node->children.find(c) == node->children.end())
            return false;
        node = node->children[c];
    }
    return true;
}