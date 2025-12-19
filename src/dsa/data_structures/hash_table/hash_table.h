// https://www.geeksforgeeks.org/dsa/c-program-hashing-chaining/

#include <iostream>
#include <vector>
#include <algorithm>

class HashTable
{

public:
    HashTable(int buckets) 
    {
        bucketCount = buckets;
        table.resize(bucketCount);
    }

    void insert(int key) 
    {
        int index = getHashIndex(key);
        table[index].push_back(key);
    }

    void remove(int key) 
    {
        int index = getHashIndex(key);
        auto it = std::find(table[index].begin(), table[index].end(), key);

        if (it != table[index].end())
            table[index].erase(it);
    }

    bool contains(int key) const
    {        
        int index = getHashIndex(key);
        auto it = std::find(table[index].begin(), table[index].end(), key);

        if (it != table[index].end())
            return true;
        else
            return false;

    }

    void display() const
    {
        for (int i = 0; i < bucketCount; i++) 
        {
            std::cout << i;
            for (int key : table[i]) 
                std::cout << " --> " << key;
            std::cout << std::endl;
        }
    }

private:
    int getHashIndex(int key) const
    {
        return key % bucketCount;
    }
    
    int bucketCount;
    std::vector<std::vector<int>> table;
};

/*
int main() {
    vector<int> keys = {7, 18, 12, 25};

    Hash hashTable(7);

    for (int key : keys) {
        hashTable.insert(key);
    }

    hashTable.remove(12);

    hashTable.display();

    return 0;
}*/