#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
	int answer = 0;
	const int size = absolutes.size();
	for (int i = 0; i < size; ++i)
	{
		answer += signs[i] ? +absolutes[i] : -absolutes[i];
	}
	return answer;
}