#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers)
{
	vector<int> answer;

	int a1[] = { 1,2,3,4,5 };
	int a1Size = 5;
	int a2[] = { 2,1,2,3,2,4,2,5 };
	int a2Size = 8;
	int a3[] = { 3,3,1,1,2,2,4,4,5,5 };
	int a3Size = 10;

	int cnt[3] = { 0 };
	int size = answers.size();
	for (int i = 0; i < size; ++i)
	{
		if (answers[i] == a1[i % a1Size])
			cnt[0] ++;
		if (answers[i] == a2[i % a2Size])
			cnt[1] ++;
		if (answers[i] == a3[i % a3Size])
			cnt[2] ++;
	}
	int m = max(cnt[2], max(cnt[0], cnt[1]));
	for (int i = 0; i < 3; ++i)
	{
		if (cnt[i] == m)answer.push_back(i + 1);
	}
	return answer;
}