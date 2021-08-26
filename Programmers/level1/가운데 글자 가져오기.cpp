#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	int sLen = s.length();
	bool oddNum = (sLen & 1) == 1;
	return s.substr(oddNum ? sLen / 2 : sLen / 2 - 1, oddNum ? 1 : 2);
}