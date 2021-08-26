#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<float, int>& p1, const pair<float, int>& p2)
{
	if (p1.first == p2.first)
		return p1.second < p2.second;
	else return p1.first > p2.first;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> reachs(N + 2);
	for (int i = stages.size() - 1; i >= 0; --i)
		reachs[stages[i]] ++;

	const int size = stages.size();
	int person = size;

	vector<pair<double, int>> v(N);
	for (int i = 0; i < N; ++i)
	{
		double rate = person == 0 ? 0 : reachs[i + 1] / (double)person;
		v[i] = { rate,i + 1 };
		person -= reachs[i + 1];
	}
	sort(v.begin(), v.end(), compare);
	vector<int> answer(N);
	for (int i = 0; i < N; ++i)
	{
		answer[i] = v[i].second;
	}
	return answer;
}