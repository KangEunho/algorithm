#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<string> solution(vector<string> strings, int n) {
	N = n;
	sort(strings.begin(), strings.end(), [](string s1, string s2)-> bool
		{
			if (s1[N] == s2[N])return s1 < s2;
			return s1[N] < s2[N];
		});
	return strings;
}