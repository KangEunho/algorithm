#include <string>
#include <vector>

using namespace std;

bool func(int s, int n)
{
	int num = 0;
	for (int i = s; num < n; ++i)
	{
		num += i;
		if (num == n)
			return true;
	}
	return false;
}
int solution(int n) {
	int answer = 0;

	for (int i = 1; i < n * 0.5f; ++i)
	{
		answer += func(i, n);
	}

	return answer + 1;
}