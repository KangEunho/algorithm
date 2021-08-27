#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
	string answer = "";

	int start = 0;
	int end = 0;
	vector<int> v;
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == ' ')
		{
			v.push_back(stoi(s.substr(start, i - start)));
			start = i + 1;
		}
	}
	v.push_back(stoi(s.substr(start, s.length() - start)));
	auto pair = minmax_element(v.begin(), v.end());
	answer.append(to_string(*pair.first));
	answer.append(" ");
	answer.append(to_string(*pair.second));

	return answer;
}