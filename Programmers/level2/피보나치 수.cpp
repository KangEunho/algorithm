#include<iostream>
using namespace std;

long long fibonacci(int n)
{
	long long prevOfprev = 0;
	long long prev = 1;
	long long cur;
	for (int i = 2; i <= n; ++i)
	{
		cur = prev + prevOfprev;
		prevOfprev = prev;
		prev = cur;
	}
	return cur;
}

int main()
{
	int testCase = 10;
	long long testAnswer = fibonacci(testCase);

	cout << testAnswer;
}