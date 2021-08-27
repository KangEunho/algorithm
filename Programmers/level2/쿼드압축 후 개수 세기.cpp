#include <string>
#include <vector>

using namespace std;
struct my_pair
{
	int a = 0, b = 0;
	my_pair(int a, int b) : a(a), b(b) {}
	my_pair operator + (const my_pair& pair)
	{
		return my_pair(a + pair.a, b + pair.b);
	}
};

my_pair quard(const vector<vector<int>>& arr, int _x, int _y, int n)
{
	int val = arr[_x][_y];
	bool wrong = false;
	for (int x = 0; x < n; ++x)
	{
		for (int y = 0; y < n; ++y)
		{
			if (arr[x + _x][y + _y] != val)
			{
				wrong = true;
				break;
			}
		}
		if (wrong)break;
	}
	if (wrong)
	{
		my_pair pair(0, 0);
		pair = pair + quard(arr, _x, _y, n / 2);
		pair = pair + quard(arr, _x + n / 2, _y, n / 2);
		pair = pair + quard(arr, _x, _y + n / 2, n / 2);
		pair = pair + quard(arr, _x + n / 2, _y + n / 2, n / 2);
		return pair;
	}
	return val == 0 ? my_pair(1, 0) : my_pair(0, 1);
}

vector<int> solution(vector<vector<int>> arr) {
	my_pair pair = quard(arr, 0, 0, arr.size());
	return { pair.a, pair.b };
}