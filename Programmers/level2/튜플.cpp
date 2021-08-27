#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <sstream>
using namespace std;

vector<int> solution(string s) {
	vector<int> answer;

	vector<vector<int>> v;
	const int length = s.length();
	for (int i = 1, j = 1; i < length - 1; ++i)
	{
		if (s[i] == '{')
			j = i;
		else if (s[i] == '}')
		{
			stringstream ss(s.substr(j + 1, i - j - 1));
			string split;
			v.push_back(vector<int>());
			while (getline(ss, split, ','))
			{
				v.back().push_back(stoi(split));
			}
		}
	}
	sort(v.begin(), v.end(), [](const vector<int>& v1, const vector<int>& v2) {return v1.size() < v2.size(); });

	answer.push_back(v[0][0]);
	for (int i = 1; i < v.size(); ++i)
	{
		multiset<int> ms(v[i - 1].begin(), v[i - 1].end());
		for (int j = 0; j < v[i].size(); ++j)
		{
			int val = v[i][j];
			if (ms.count(val) == 0)
			{
				answer.push_back(val);
				break;
			}
			else
			{
				ms.erase(ms.find(val));
			}
		}
	}
	return answer;
}