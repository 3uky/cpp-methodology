// https://www.educba.com/c-plus-plus-mutable/

#pragma once

class Mutable
{
public:
    void ChangeMutableVariable() const 
    {
        m_mutable_var++; // mutable variables could be changed in const method
    }

    int GetValue() const
    {
        return m_mutable_var;
    }

    /* // compilation error: cannot be changed non-mutable variable in constant method
    bool ChangeNormalVariable() const
    {
        m_not_mutable++;
    }
    */

private:
    //int m_not_mutable;
    mutable int m_mutable_var;
};
