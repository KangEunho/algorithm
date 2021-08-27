#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const vector<string>& v1, const vector<string>& v2)
{
	if (v1[0] == v2[0])
		return v1[1] < v2[1];
	return v1[0] < v2[0];
}

int use[1000] = { 0 };
vector<string> dfs(const vector<vector<string>>& tickets, const int ticketCount, vector<string>& v)
{
	string cur = v[v.size() - 1];
	for (int i = 0; i < ticketCount; ++i)
	{
		if (use[i])continue;
		if (tickets[i][0] == cur)
		{
			use[i] = true;
			v.push_back(tickets[i][1]);
			vector<string> answer = dfs(tickets, ticketCount, v);
			if (answer.size() == ticketCount + 1)
			{
				return answer;
			}
			v.pop_back();
			use[i] = false;
		}
	}
	return v;
}
vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;

	sort(tickets.begin(), tickets.end(), cmp);
	answer.push_back("ICN");
	answer = dfs(tickets, tickets.size(), answer);
	return answer;
}