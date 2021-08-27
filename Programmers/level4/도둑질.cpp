#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
	const int size = money.size();
	vector<int> d(size);
	vector<int> d2(size);
	d[0] = 0;
	d[1] = money[1];
	d2[0] = money[0];
	d2[1] = money[0];

	for (int i = 2; i < size; ++i)
	{
		d[i] = max(d[i - 2] + money[i], d[i - 1]);
	}
	for (int i = 2; i < size - 1; ++i)
	{
		d2[i] = max(d2[i - 2] + money[i], d2[i - 1]);
	}
	return max(d[size - 1], d2[size - 2]);
}