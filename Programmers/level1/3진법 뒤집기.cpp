#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
	int answer = 0;
	vector<int> v;
	while (n > 0)
	{
		v.push_back(n % 3);
		n /= 3;
	}
	const int size = v.size();
	for (int i = 0; i < size; ++i)
		answer = answer * 3 + v[i];
	return answer;
}