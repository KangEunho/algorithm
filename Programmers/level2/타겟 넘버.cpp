#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dfs(int index, int sum, const vector<int>& numbers, const int target)
{
	if (index >= numbers.size())
		return sum == target;

	return dfs(index + 1, sum + numbers[index], numbers, target) + dfs(index + 1, sum - numbers[index], numbers, target);
}

int solution(vector<int> numbers, int target) {
	int answer = dfs(0, 0, numbers, target);
	return answer;

}