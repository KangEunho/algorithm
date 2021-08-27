#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	int whiteSpaceIdx = -1;
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == ' ')whiteSpaceIdx = i;
		else
		{
			bool oddNum = (i - whiteSpaceIdx + 1) & 1;
			s[i] = oddNum ? tolower(s[i]) : toupper(s[i]);
		}
	}
	return s;
}