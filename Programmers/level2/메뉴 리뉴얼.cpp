#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int courses[11] = { false };
void back(unordered_map<string, int>& um, string order, int i, string m, bool add)
{
	if (add && courses[m.length()])
	{
		um[m]++;
	}
	if (i == order.size())
		return;
	back(um, order, i + 1, m + order[i], true);
	back(um, order, i + 1, m, false);
}

vector<string> solution(vector<string> orders, vector<int> course) {
	unordered_map<string, int> um;
	vector<string> answer;

	for (int i = 0; i < course.size(); ++i)
	{
		courses[course[i]] = true;
	}

	for (int i = 0; i < orders.size(); ++i)
	{
		sort(orders[i].begin(), orders[i].end());
		back(um, orders[i], 0, "", false);
	}

	int cnt[11] = { 0 };
	for (auto p : um)
	{
		cnt[p.first.length()] = max(cnt[p.first.length()], p.second);
	}

	for (auto p : um)
	{
		if (cnt[p.first.length()] >= 2 && p.second == cnt[p.first.length()])
			answer.push_back(p.first);
	}
	sort(answer.begin(), answer.end());
	return answer;
}