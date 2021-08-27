#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
	const int length = s.length();
	for (int i = 0; i < length; ++i)
	{
		char c = s[i];
		if (c == ' ')continue;
		if (c >= 'a' && c <= 'z')
			s[i] = 'a' + ((s[i] - 'a' + n) % 26);
		else if (c >= 'A' && c <= 'Z')
			s[i] = 'A' + ((s[i] - 'A' + n) % 26);
	}
	return s;
}