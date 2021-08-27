#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
	int pCount = 0, yCount = 0;
	for (char c : s)
	{
		if (c == 'p' || c == 'P')pCount++;
		else if (c == 'y' || c == 'Y')yCount++;
	}

	return pCount == yCount;
}