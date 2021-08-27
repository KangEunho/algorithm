#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;
	vector<bool> check(n + 1);
	for (int i = 2; i <= n; ++i)
	{
		if (check[i])continue;
		answer++;
		for (int j = i; j <= n; j += i)
			check[j] = true;

	}
	return answer;
}