// https://www.cplusplus.com/reference/set/set/

// set - unique values, immutable, items could be removed or inserted but not modified, unordered set is more efficient for access by key less for iterating
// list - faster for inserting, moving, sorting, extracting than vector, array, deque. Cannot direct access by position.
// array - like c array it has static size, extended with methods
// vector - dynamic array
// map - association field, binary tree search (log n)
// unordered_map - association field, hash search (const)

#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <array>

using namespace std;

class MyArray
{
    array<int, 10> m_array;

	void Initialization()
    {
        for(int i = 0; i < 10; i++)
            m_array.at(i) = i + 1;
    }

    void Print() const
    {
        // print content:
        cout << "Array contains:";
        for(int i = 0; i < 10; i++)
            cout << ' ' << m_array.at(i);
        cout << '\n';
    }

};
class MyVector
{
    void Init() {
        std::vector<int> myvector (3,100); // 100 100 100
        std::vector<int>::iterator it;

        it = myvector.begin();
        it = myvector.insert ( it , 200 ); // 200 100 100 100

        myvector.insert (it,2,300); // 300 300 200 100 100 1000

        // "it" no longer valid, get a new one:
        it = myvector.begin();

        std::vector<int> anothervector (2,400);
        myvector.insert (it+2,anothervector.begin(),anothervector.end()); // 300 300 400 400 200 100 100 100

        int myarray [] = { 501,502,503 };
        myvector.insert (myvector.begin(), myarray, myarray+3); // 501 502 503 300 300 400 400 200 100 100 100
    }

    void Print(vector<int>& vec) const
    {
        cout << "myvector contains:";
        for (std::vector<int>::iterator it = vec.begin(); it < vec.end(); it++)
            cout << ' ' << *it;
        cout << endl;
    }


};

class MyList
{
    std::list<int> m_list;

    void Init()
    {
        std::list<int> m_list2(4, 100); // four int with value 100
    }
};

class MySet
{
    set<int> m_set;

    void Init()
    {
        int ints[] = { 75, 23, 65, 42, 13, 75, 65, 9 };
        for (auto val : ints)
            m_set.insert(val);
    }

    void Print_with_iterator() const
    {
        for (set<int>::iterator it = m_set.begin(); it != m_set.end(); ++it)
            cout << ' ' << *it;
        cout << '\n';
    }

    void Print_with_auto_range() const
    {
        for (auto it : m_set)
            cout << ' ' << it;
        cout << '\n';
    }
};

class MyMap
{
    std::map<char, int> m_map;

    void Init() {
        // initialization with value
    	m_map['a'] = 10;
        m_map['b'] = 30;
        m_map['c'] = 50;
        m_map['d'] = 70;

        // initialization with map
        std::map<char, int> new_map(m_map.begin(), m_map.end());

        std::cout << "second['a'] is " << new_map['a'] << '\n';
    }

 
};

    
