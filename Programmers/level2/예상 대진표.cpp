#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
	int answer = 0;

	while ((a + 1) >> 1 != (b + 1) >> 1)
	{
		answer++;
		a = (a + 1) >> 1;
		b = (b + 1) >> 1;
	}

	return answer + 1;
}