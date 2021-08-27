#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
	if (N == number)
		return 1;
	int nn = N;
	vector<unordered_set<int>> dp(9);
	dp[1].insert(nn);

	for (int i = 2; i < 9; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			int k = i - j;

			for (auto dpj : dp[j])
			{
				for (auto dpk : dp[k])
				{
					dp[i].insert(dpj + dpk);
					if (dpj - dpk > 0)
						dp[i].insert(dpj - dpk);
					dp[i].insert(dpj * dpk);
					if (dpj / dpk > 0)
						dp[i].insert(dpj / dpk);
					if (dpk / dpj > 0)
						dp[i].insert(dpk / dpj);
				}
			}
		}
		dp[i].insert(nn = nn * 10 + N);
		if (dp[i].find(number) != dp[i].end())
			return i;
	}

	return -1;
}