#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	bool visit[100][100] = { false };
	int dirX[] = { -1, 0, 0, 1 };
	int dirY[] = { 0, 1, -1, 0 };

	queue<pair<int, int>> q;
	for (int x = 0; x < m; ++x)
	{
		for (int y = 0; y < n; ++y)
		{
			if (visit[x][y]) continue;
			if (picture[x][y] == 0)continue;

			int val = picture[x][y];
			number_of_area++;
			q.push({ x, y });

			int size_of_one_area = 0;
			while (q.empty() == false)
			{
				int _x = q.front().first;
				int _y = q.front().second;
				q.pop();
				if (visit[_x][_y]) continue;
				if (picture[_x][_y] != val)continue;
				visit[_x][_y] = true;
				size_of_one_area++;
				for (int i = 0; i < 4; ++i)
				{
					int nx = _x + dirX[i];
					int ny = _y + dirY[i];
					if (nx >= 0 && nx < m && ny >= 0 && ny < n)
					{
						q.push({ nx, ny });
					}
				}
			}
			max_size_of_one_area = max(max_size_of_one_area, size_of_one_area);
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}