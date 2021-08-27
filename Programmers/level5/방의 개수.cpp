#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

struct pair_hash
{
	inline size_t operator()(const pair<int, int>& v) const
	{
		hash<int> int_hasher;
		return int_hasher(v.first) * 91 ^ int_hasher(v.second) * 81;
	}
};

struct pair_pair_hash
{
	inline size_t operator()(const pair<pair<int, int>, pair<int, int>>& v) const
	{
		hash<int> int_hasher;
		return int_hasher(v.first.first) * 91 ^ int_hasher(v.first.second) * 81 ^ int_hasher(v.second.first) * 71 ^ int_hasher(v.second.second) * 61;
	}
};
int solution(vector<int> arrows) {
	const int dir_x[] = { 0,1,1,1,0,-1,-1,-1 };
	const int dir_y[] = { 1,1,0,-1,-1,-1,0,1 };
	unordered_set<pair<int, int>, pair_hash> nodeVisit;
	unordered_set<pair<pair<int, int>, pair<int, int>>, pair_pair_hash> edgeVisit;

	int x = 0, y = 0;
	const int arrowSize = arrows.size();
	nodeVisit.insert({ x, y });
	int answer = 0;
	for (int i = 0; i < arrowSize; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			int nx = x + dir_x[arrows[i]];
			int ny = y + dir_y[arrows[i]];

			if (nodeVisit.find({ nx, ny }) != nodeVisit.end() && edgeVisit.find({ {x, y}, { nx, ny } }) != edgeVisit.end())
			{
				answer++;
			}
			else
				nodeVisit.insert({ nx, ny });

			edgeVisit.insert({ {x, y}, { nx, ny } });
			edgeVisit.insert({ {nx, ny}, { x, y } });
			x = nx;
			y = ny;
		}
	}

	return answer;
}