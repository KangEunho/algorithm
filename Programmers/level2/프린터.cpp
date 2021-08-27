#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location)
{
	int answer = 0;
	queue<pair<int, int>> queue;
	for (int i = 0; i < priorities.size(); ++i)
	{
		queue.push(make_pair(i, priorities[i]));
	}

	sort(priorities.begin(), priorities.end(), greater<>());

	while (queue.empty() == false)
	{
		auto front = queue.front();
		queue.pop();
		if (front.second == priorities[answer])
		{
			answer++;
			if (front.first == location)
				break;
		}
		else
		{
			queue.push(front);
		}
	}

	return answer;
}