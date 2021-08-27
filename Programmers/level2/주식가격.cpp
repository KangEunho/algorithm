#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices)
{
	int size = prices.size();
	vector<int> answer(size); // 0값으로 size 만큼 생성

	stack<int> s;
	s.push(0);

	for (int i = 1; i < size; ++i)
	{
		while (!s.empty() && prices[s.top()] > prices[i])
		{
			int c = s.top();
			answer[c] = i - c;
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty())
	{
		int c = s.top();
		answer[c] = size - c - 1;
		s.pop();
	}
	return answer;
}