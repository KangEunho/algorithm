#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isPrime(int n)
{
	if (n < 2)return false;
	if (n == 2)return true;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)return false;
	}
	return true;
}

bool check[10];

void func(int n, string& numbers, vector<int>& vec)
{
	if (isPrime(n))
	{
		vec.push_back(n);
	}

	int length = numbers.length();
	for (int i = 0; i < length; ++i)
	{
		if (check[i] == false)
		{
			check[i] = true;
			func(n * 10 + numbers[i] - '0', numbers, vec);
			check[i] = false;
		}
	}
}

int solution(string numbers)
{
	int length = numbers.length();
	bool search[10] = { false };
	search[0] = true;
	vector<int> primes;

	for (int i = 0; i < length; ++i)
	{
		if (search[numbers[i] - '0'] == true)continue;
		search[numbers[i] - '0'] = true;
		check[i] = true;
		func(numbers[i] - '0', numbers, primes);
		check[i] = false;
	}

	sort(primes.begin(), primes.end());
	primes.erase(unique(primes.begin(), primes.end()), primes.end());
	return primes.size();
}