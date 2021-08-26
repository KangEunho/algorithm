#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
	vector<int> answer;
	int c = commands.size();
	for (int t = 0; t < c; ++t)
	{
		int i = commands[t][0];
		int j = commands[t][1];
		int k = commands[t][2];
		int size = j - i + 1;
		vector<short> v(size);
		for (int q = 0; q < size; ++q)
		{
			v[q] = array[i + q - 1];
		}
		sort(v.begin(), v.end());
		answer.push_back(v[k - 1]);
	}
	return answer;
}