#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;

	int size = truck_weights.size();

	queue<int> queue;
	for (int i = 0; i < bridge_length; ++i)
		queue.push(0);

	int truckIndex = 0;
	int curWeight = 0;
	int goal = 0;

	while (true)
	{
		answer++;
		int cur = queue.front();
		queue.pop();
		if (cur > 0)
		{
			curWeight -= cur;
			if (++goal == size)
				break;
		}
		int truckWeight = truck_weights[truckIndex];
		if (truckIndex < size && truckWeight + curWeight <= weight)
		{
			curWeight += truckWeight;
			queue.push(truckWeight);
			truckIndex++;
		}
		else
			queue.push(0);
	}

	return answer;
}