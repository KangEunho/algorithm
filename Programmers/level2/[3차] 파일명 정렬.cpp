#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
pair<string, string> getHeadAndNumber(string str)
{
	pair<string, string> p;
	int firstIndex = -1;
	for (int i = 0; i < str.length(); ++i)
	{
		if (firstIndex == -1)
		{
			if (isdigit(str[i]))
			{
				firstIndex = i;
			}
		}
		else
		{
			if (isdigit(str[i]) == false)
			{
				p.first = str.substr(0, firstIndex);
				p.second = str.substr(firstIndex, i - firstIndex);
				return p;
			}
		}
	}
	p.first = str.substr(0, firstIndex);
	p.second = str.substr(firstIndex, str.length() - firstIndex);
	return p;
}

bool compare(const string& s1, const string& s2)
{
	auto s1HeadNumber = getHeadAndNumber(s1);
	auto s2HeadNumber = getHeadAndNumber(s2);
	transform(s1HeadNumber.first.begin(), s1HeadNumber.first.end(), s1HeadNumber.first.begin(), ::tolower);
	transform(s2HeadNumber.first.begin(), s2HeadNumber.first.end(), s2HeadNumber.first.begin(), ::tolower);
	if (s1HeadNumber.first == s2HeadNumber.first)
	{
		return stoi(s1HeadNumber.second) < stoi(s2HeadNumber.second);
	}
	else
		return s1HeadNumber.first < s2HeadNumber.first;
	return true;
}
vector<string> solution(vector<string> files) {
	stable_sort(files.begin(), files.end(), compare);
	return files;
}