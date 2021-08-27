#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getParent(vector<int>& parent, int x)
{
	if (parent[x] == x)return x;
	return parent[x] = getParent(parent, parent[x]);
}

void unionParent(vector<int>& parent, int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b)parent[b] = a;
	else parent[a] = b;
}

bool sameParent(vector<int>& parent, int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	return a == b;
}

bool cmp(const vector<int>& a, const vector<int>& b)
{
	return a[2] < b[2];
}
int solution(int n, vector<vector<int>> costs) {

	sort(costs.begin(), costs.end(), cmp);

	vector<int> parent(n);
	for (int i = 0; i < n; ++i)
		parent[i] = i;

	int answer = 0;
	for (int i = 0; i < costs.size(); ++i)
	{
		if (!sameParent(parent, costs[i][0], costs[i][1]))
		{
			answer += costs[i][2];
			//unionParent(parent, costs[i][0], costs[i][1]);
		}
	}
	return answer;
}