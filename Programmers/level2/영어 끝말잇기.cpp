#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;
vector<int> solution(int n, vector<string> words) {

	unordered_set<string> used_word;
	used_word.insert(words[0]);
	char last = words[0].back();
	for (int i = 1; i < words.size(); ++i)
	{
		if (used_word.find(words[i]) != used_word.end() || last != words[i][0])
		{
			return { i % n + 1 , i / n + 1 };
		}
		used_word.insert(words[i]);
		last = words[i].back();
	}
	return { 0,0 };
}