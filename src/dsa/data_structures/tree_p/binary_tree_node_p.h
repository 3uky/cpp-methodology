#pragma once

#include <memory>

namespace algorithms
{

class NodeP
{
public:
    int m_data;
    NodeP *left, *right;

    NodeP(int key) 
    {
        m_data = key;
        left = nullptr;
        right = nullptr;
    }

    int GetValue() const
    {
        return m_data;
    }
};

}