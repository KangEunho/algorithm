#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	const int size = cities.size();
	vector<string> cache;
	for (int i = 0; i < size; ++i)
	{
		transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
		auto finditer = find(cache.begin(), cache.end(), cities[i]);
		if (finditer != cache.end())
		{
			cache.erase(finditer);
			cache.push_back(cities[i]);
			answer += 1;
		}
		else
		{
			answer += 5;
			cache.push_back(cities[i]);
			if (cache.size() > cacheSize)
				cache.erase(cache.begin());
		}
	}

	return answer;
}