#include <string>
#include <vector>

using namespace std;

inline int GetDay(int p, int s)
{
	int d = (100 - p) / s;
	if (p + s * d < 100)
		return d + 1;
	return d;
}
vector<int> solution(vector<int> progresses, vector<int> speeds)
{
	vector<int> answer;
	int size = progresses.size();
	int checkI = 0;
	int checkD = GetDay(progresses[0], speeds[0]);
	for (int i = 1; i < size; ++i)
	{
		int d = GetDay(progresses[i], speeds[i]);
		if (d > checkD)
		{
			answer.push_back(i - checkI);
			checkI = i;
			checkD = d;
		}
	}
	answer.push_back(size - checkI);
	return answer;
}