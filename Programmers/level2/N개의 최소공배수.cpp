#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int solution(vector<int> arr) {
	int answer = 0;
	int size = arr.size();
	for (int i = 1; i < size; ++i)
	{
		int g = gcd(arr[i - 1], arr[i]);
		int lcm = g * (arr[i - 1] / g) * (arr[i] / g);
		arr[i] = lcm;
	}
	return arr[size - 1];
}