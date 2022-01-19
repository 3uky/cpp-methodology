// https://www.cplusplus.com/reference/set/set/

// set - unique values, immutable, items could be removed or inserted but not modified, unordered set is more efficient for access by key less for iterating
// list - faster for inserting, moving, sorting, extracting than vector, array, deque. Cannot direct access by position.
// array - like c array it has static size, extended with methods
// vector - dynamic array
// map - association field, binary tree search (log n)
// unordered_map - association field, hash search (const)

#ifndef T_CONTEINERS_H
#define T_CONTEINERS_H

#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

class T_conteiners
{
public:
    static void test() {
        //test_set();
        //test_array();
        //test_vector();
        //test_map();
        test_list();
    }

    static int test_set() {
        int myints[] = {75,23,65,42,13};
        set<int> myset (myints,myints+5);

        cout << "myset contains:";
        for (set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
            cout << ' ' << *it;
        cout << '\n';

        for (auto it : myset)
            cout << ' ' << it;

        return 0;
    }

    static int test_array() {
        std::array<int,10> myarray;

        // assign some values:
        for (int i=0; i<10; i++) myarray.at(i) = i+1;

        // print content:
        std::cout << "myarray contains:";
        for (int i=0; i<10; i++)
        std::cout << ' ' << myarray.at(i);
        std::cout << '\n';

        return 0;
    }

    static int test_vector () {
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

        std::cout << "myvector contains:";
        for (it=myvector.begin(); it<myvector.end(); it++)
            std::cout << ' ' << *it;
        std::cout << '\n';

        return 0;
    }

    static int test_map() {
        std::map<char,int> first;

        first['a']=10;
        first['b']=30;
        first['c']=50;
        first['d']=70;

        std::map<char,int> second (first.begin(),first.end());

        std::cout << "second['a'] is " << second['a'] << '\n';

        return 0;
    }

    static void test_list() {
        // constructors used in the same order as described above:
        std::list<int> first;                                // empty list of ints
        std::list<int> second (4,100);                       // four ints with value 100
    }
};

#endif // T_CONTEINERS_H
