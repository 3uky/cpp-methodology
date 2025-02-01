#pragma once

#include <memory>

namespace algorithms
{

class Node
{
public:
    Node(int data) : m_data(data) {}

    int GetValue() const
    {
        return m_data;
    }

    std::unique_ptr<Node> left = nullptr;
    std::unique_ptr<Node> right = nullptr;

private:
    int m_data;
};

}