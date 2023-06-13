// https://www.educba.com/c-plus-plus-mutable/

#pragma once

class T_mutable
{
    bool m_flag;
    mutable int m_Count;

public:
    bool FlagFunction() const {
        m_Count++;
        return m_flag;
    }
};
