#pragma once

#include <algorithm>
#include <functional>
#include <vector>
#include <list>

namespace cpp_internals
{
    
template <typename TKey, typename TValue>
class HashMap
{
    public:
        HashMap(int64_t size = 100) : m_buckets(size, std::list<std::pair<TKey, TValue>>())
		{
        }

        TValue Get(TKey& key) const
		{
            auto index = GetIndex(key);
            auto result = find_if(m_buckets.at(index).begin(), m_buckets.at(index).end(), [&key](const std::pair<TKey,TValue>& obj) {return obj.first == key; });

        	return result == m_buckets[index].end() ? NULL : result->second;
        }

        void Put(TKey key, TValue value)
		{
            m_buckets.at(GetIndex(key)).push_back(std::make_pair(key, value));
        }

    private:
        std::vector<std::list<std::pair<TKey, TValue>>> m_buckets;

        std::size_t GetIndex(TKey& key) const
		{
            std::size_t hash = std::hash<TKey>{}(key);
            return hash % m_buckets.size();
        }
};

}