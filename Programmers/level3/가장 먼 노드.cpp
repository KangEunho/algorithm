#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
	vector<vector<int>> edge2(n + 1);
	int edgeSize = edge.size();

	for (int i = 0; i < edgeSize; ++i)
	{
		edge2[edge[i][0]].push_back(edge[i][1]);
		edge2[edge[i][1]].push_back(edge[i][0]);
	}

	vector<int> distance(n + 1, -1);
	distance[1] = 0;
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < edge2[cur].size(); ++i)
		{
			int next = edge2[cur][i];
			if (distance[next] == -1)
			{
				distance[next] = distance[cur] + 1;
				q.push(next);
			}
		}
	}
	sort(distance.begin(), distance.end(), greater<int>());

	int answer = 0;
	for (int i = 0; i < n + 1; ++i)
	{
		if (distance[i] == distance[0])
			answer++;
		else break;
	}

	return answer;
}