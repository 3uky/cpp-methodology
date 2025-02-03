#include <map>
#include <vector>
#include <algorithm>

// exercise description: arrange elements base on their frequency

namespace leet_code
{
	class FrequencySort
	{
	public:
		std::vector<int> Sort(std::vector<int>& arr)
		{
			CountFrequency(arr);
			return GenerateSortedSequence();
		}

	private:
		void CountFrequency(std::vector<int>& arr)
		{
			for (auto element : arr)
			{
				auto it = m_frequency_counter.find(element);
				if(it != m_frequency_counter.end())
				{
					it->second++;
				}
				else
				{
					m_frequency_counter.emplace(element, 1);
				}
			}
		}

		std::vector<int> GenerateSortedSequence()
		{
			std::vector<int> sorted;
			std::vector<std::pair<int, int>> sorted_frequency_counter(m_frequency_counter.begin(), m_frequency_counter.end());
			std::sort(sorted_frequency_counter.begin(), sorted_frequency_counter.end(), Compare);
			std::transform(sorted_frequency_counter.begin(), sorted_frequency_counter.end(), std::back_inserter(sorted), [](const std::pair<int, int>& p) { return p.first; });
			return sorted;
		}

		static bool Compare(std::pair<int, int> a, std::pair<int, int> b)
		{
			if (a.second == b.second)
				return a.first > b.first;			
			return a.second > b.second;
		}
		std::map<int, int> m_frequency_counter;
	};
}
