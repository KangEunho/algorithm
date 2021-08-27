#include<vector>
#include <queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
	int dirX[] = { 0, 0, 1, -1 };
	int dirY[] = { 1, -1, 0, 0 };
	int n = maps.size();
	int m = maps[0].size();
	vector<vector<int>> visit(n, vector<int>(m, -1));
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	visit[0][0] = 1;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dirX[i];
			int ny = y + dirY[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
			if (visit[nx][ny] != -1) continue;
			if (maps[nx][ny] == 0)continue;
			visit[nx][ny] = visit[x][y] + 1;
			q.push({ nx, ny });
		}
	}
	return visit[n - 1][m - 1];
}