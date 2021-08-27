#include <string>
#include <vector>

using namespace std;

string solution(string s) {

	int spaceIndex = -1;
	int sLen = s.length();

	for (int i = 0; i < sLen; ++i)
	{
		if (i == spaceIndex + 1)
		{
			if (s[i] == ' ')
				spaceIndex = i;
			else if (s[i] >= 'a' && s[i] <= 'z')
				s[i] -= 'a' - 'A';
		}
		else
		{
			if (s[i] == ' ')
				spaceIndex = i;
			else if (s[i] >= 'A' && s[i] <= 'Z')
				s[i] += 'a' - 'A';
		}
	}
	return s;
}