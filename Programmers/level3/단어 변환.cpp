#include <iostream>
#include <vector>
#include <queue>>
#include <set>
using namespace std;

bool isDifferenceOneChar(string s1, string s2)
{
	int sLen = s1.length();
	if (sLen != s2.length())return false;
	int difCount = 0;
	for (int i = 0; i < sLen; ++i)
	{
		if (s1[i] != s2[i])
		{
			if (++difCount == 2)return false;
		}
	}
	return difCount == 1;
}

int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	const int wordSize = words.size();
	queue<pair<int, string>> q;
	q.push({ 0, begin });
	set<string> visit;
	while (!q.empty())
	{
		auto item = q.front();
		q.pop();
		if (item.second == target)
		{
			answer = item.first;
			break;
		}
		const int sLen = item.second.length();
		for (int i = 0; i < sLen; ++i)
		{
			if (item.second[i] != target[i])
			{
				for (int j = 0; j < wordSize; ++j)
				{
					if (visit.find(words[j]) == visit.end() && isDifferenceOneChar(item.second, words[j]))
					{
						q.push({ item.first + 1, words[j] });
						visit.insert(words[j]);
					}
				}
			}
		}
	}
	return answer;
}