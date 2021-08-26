#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer(n);
	for (int i = 0; i < n; ++i)
	{
		int num = arr1[i] | arr2[i];
		for (int j = 0; j < n; ++j)
		{
			answer[i] = num & 1 == 1 ? '#' + answer[i] : ' ' + answer[i];
			num >>= 1;
		}
	}

	return answer;
}