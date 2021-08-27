#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
	int min = 2147483647;
	int idx = 1;
	int size = arr.size();
	for (int i = 0; i < size; ++i)
	{
		if (min > arr[i]) {
			min = arr[i];
			idx = i;
		}
	}
	arr.erase(arr.begin() + idx);
	return arr.empty() ? vector<int>(1, -1) : arr;
}