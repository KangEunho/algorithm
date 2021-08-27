#include <string>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int solution(vector<int> scoville, int K)
{
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> queue;
	for (int s : scoville)
	{
		queue.push(s);
	}

	while (!queue.empty())
	{
		int q1 = queue.top();
		queue.pop();
		if (q1 >= K)
			break;
		if (queue.empty())
			return -1;
		int q2 = queue.top();
		queue.pop();
		int q3 = q1 + q2 + q2;
		queue.push(q3);
		answer++;
	}
	return answer;
}