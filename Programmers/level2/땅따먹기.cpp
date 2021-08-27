#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
	int row = land.size();
	vector<vector<int>> dp(row, vector<int>(4));

	for (int i = 0; i < 4; ++i)
	{
		dp[0][i] = land[0][i];
	}

	for (int i = 1; i < row; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			int max = 0;
			for (int k = 0; k < 4; ++k)
			{
				if (j == k)
					continue;
				if (max < dp[i - 1][k])
					max = dp[i - 1][k];
			}
			dp[i][j] = max + land[i][j];
		}
	}

	return *max_element(dp[row - 1].begin(), dp[row - 1].end());
}