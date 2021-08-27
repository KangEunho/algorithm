#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<string> data) {
	int answer = 0;
	string member = "ACFJMNRT";
	const int dataSize = data.size();
	do
	{
		unordered_map<char, int> map;
		for (int i = 0; i < 8; ++i)
			map.insert({ member[i], i });

		bool possible = true;
		for (int i = 0; i < dataSize; ++i)
		{
			int n = map[data[i][0]];
			int f = map[data[i][2]];
			char oper = data[i][3];
			int v = data[i][4] - '0';

			int range = abs(n - f) - 1;
			if (oper == '=' && !(range == v))
			{
				possible = false;
				break;
			}
			else if (oper == '>' && !(range > v))
			{
				possible = false;
				break;
			}
			else if (oper == '<' && !(range < v))
			{
				possible = false;
				break;
			}
		}
		if (possible)answer++;
	} while (next_permutation(member.begin(), member.end()));
	return answer;
}