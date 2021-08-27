#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
	sort(times.begin(), times.end());
	const int timeSize = times.size();
	long long min = times[0] * (long long)n / timeSize;
	long long max = times[timeSize - 1] * (long long)n;
	while (min < max)
	{
		long long mid = (min + max) / 2;
		long long pass = 0;
		for (int i = 0; i < timeSize; ++i)
		{
			pass += mid / times[i];
		}
		if (pass >= n)
			max = mid;
		else min = mid;
	}

	return max;
}