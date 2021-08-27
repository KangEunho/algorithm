#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {

	vector<vector<int>> game(n + 1, vector<int>(n + 1));

	for (int i = 0; i < results.size(); ++i)
	{
		game[results[i][0]][results[i][1]] = 1;
		game[results[i][1]][results[i][0]] = -1;
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (game[j][i] != 0)
			{
				for (int k = 1; k <= n; ++k)
				{
					if (game[j][i] == game[i][k])
					{
						game[j][k] = game[j][i];
						cout << i << ' ' << j << endl;
					}
				}
			}
		}
	}


	int answer = 0;
	for (int i = 1; i <= n; ++i)
	{
		int count = 0;
		for (int j = 1; j <= n; ++j)
		{
			if (game[i][j] != 0)
				count++;
		}
		if (count == n - 1)
			answer++;
	}
	return answer;
}