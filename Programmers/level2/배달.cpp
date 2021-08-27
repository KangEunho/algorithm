#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
	int answer = 0;
	vector<pair<int, int>> v[51];
	vector<int> dist(N + 1, -1);

	for (auto r : road)
	{
		v[r[0]].push_back({ r[1] , r[2] });
		v[r[1]].push_back({ r[0] , r[2] });
	}

	priority_queue<pair<int, int>> pq;

	dist[1] = 0;
	pq.push({ 0, 1 });
	while (pq.empty() == false)
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (int i = 0; i < v[cur].size(); ++i)
		{
			int next = v[cur][i].first;
			int ncost = v[cur][i].second;

			if (dist[next] == -1 || dist[next] > cost + ncost)
			{
				dist[next] = cost + ncost;
				pq.push({ -dist[next], next });
			}
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		if (dist[i] != -1 && dist[i] <= K)answer++;
	}
	return answer;
}