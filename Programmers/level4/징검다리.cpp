#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool possible(vector<int>& rocks, int n, int minDistance)
{
	int remove = 0;
	int prev = 0;
	int size = rocks.size();
	for (int i = 0; i < size; ++i)
	{
		if (rocks[i] - prev < minDistance)
		{
			remove++;
			if (remove > n)
				return false;
		}
		else
		{
			prev = rocks[i];
		}
	}
	return true;
}

int solution(int distance, vector<int> rocks, int n) {
	sort(rocks.begin(), rocks.end());
	rocks.push_back(distance);

	int min = 0;
	int max = distance;
	int mid;
	while (min < max)
	{
		mid = (min + max) / 2;
		if (possible(rocks, n, mid))
		{
			min = mid + 1;
		}
		else max = mid;
	}

	return possible(rocks, n, min) ? min : min - 1;
}