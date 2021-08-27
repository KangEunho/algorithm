#include <iostream>
#include<string>
#include <vector>
using namespace std;

int solution(string s)
{
	vector<char> v;
	const int length = s.length();
	for (int i = 0; i < length; ++i)
	{
		v.push_back(s[i]);
		while (v.size() >= 2)
		{
			char a = v[v.size() - 2];
			char b = v.back();
			if (a == b)
				v.erase(v.end() - 2, v.end());
			else break;
		}
	}
	return v.size() == 0;
}