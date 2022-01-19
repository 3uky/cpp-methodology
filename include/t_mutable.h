// https://www.educba.com/c-plus-plus-mutable/

#ifndef T_MUTABLE_H
#define T_MUTABLE_H

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

#endif // T_MUTABLE_H
