#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	int a[26] = { 0 };

	for (int i = 0; i < skill.length(); ++i)
	{
		a[skill[i] - 'A'] = i + 1;
	}

	for (int i = 0; i < skill_trees.size(); ++i)
	{
		int skill_idx = 1;
		bool possible = true;
		for (int j = 0; j < skill_trees[i].length(); ++j)
		{
			if (a[skill_trees[i][j] - 'A'] > skill_idx)
			{
				possible = false;
				break;
			}
			else if (a[skill_trees[i][j] - 'A'] == skill_idx)
			{
				skill_idx++;
			}
		}
		if (possible)
			answer++;
	}

	return answer;
}