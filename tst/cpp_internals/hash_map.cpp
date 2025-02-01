#include "gmock/gmock.h"

#include "hash_map.h"

using namespace std;

namespace cpp_internals
{
	TEST(HashMapTest, ShouldReturnExpectedValue)
	{
		// GIVEN
		HashMap<int, int> hashMap;
		int key = 10;
		int value = 100;

		// WHEN
		hashMap.Put(key, value);
		
		// THEN
		EXPECT_EQ(hashMap.Get(key), value);
	}

	TEST(HashMapTest, ShouldReturnExpectedValueWithStringKey)
	{
		// GIVEN
		HashMap<std::string, int> hashMap;
		std::string key = "myKey", key2 = "myKey2";
		int value = 100, value2 = 200;

		// WHEN
		hashMap.Put(key, value);
		hashMap.Put(key2, value2);

		// THEN
		EXPECT_EQ(hashMap.Get(key), value);
	}

}