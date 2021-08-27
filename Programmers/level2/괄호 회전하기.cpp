#include <string>
#include <vector>
#include <stack>
using namespace std;

bool isRight(const int size, int startI, string str)
{
	stack<char> s;
	for (int i = 0; i < size; ++i)
	{
		char c = str[(startI + i) % size];
		if (c == '(' || c == '{' || c == '[') {
			s.push(c);
		}
		else
		{
			if (s.empty())
				return false;

			char top = s.top();
			if (c == ')' && top != '(')
				return false;
			if (c == '}' && top != '{')
				return false;
			if (c == ']' && top != '[')
				return false;
			s.pop();
		}
	}
	return s.empty();
}
int solution(string s) {
	int answer = 0;

	int length = s.length();
	for (int i = 0; i < length; ++i)
	{
		answer += isRight(length, i, s);
	}

	return answer;
}