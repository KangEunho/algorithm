#include <string>
#include <unordered_map>
using namespace std;

int solution(string str1, string str2) {
	unordered_map<string, int> map1;
	unordered_map<string, int> map2;

	for (int i = 0; i < str1.length() - 1; ++i)
	{
		if (isalpha(str1[i]) && isalpha(str1[i + 1]))
		{
			char ch[3] = { (char)tolower(str1[i]), (char)tolower(str1[i + 1]) };
			map1[string(ch)]++;
		}
	}
	for (int i = 0; i < str2.length() - 1; ++i)
	{
		if (isalpha(str2[i]) && isalpha(str2[i + 1]))
		{
			char ch[3] = { (char)tolower(str2[i]), (char)tolower(str2[i + 1]) };
			map2[string(ch)]++;
		}
	}
	int gyo = 0;
	for (auto m : map1)
	{
		if (map2[m.first] > 0)
			gyo += min(m.second, map2[m.first]);
		else
			map2[m.first] = m.second;
	}
	int hap = 0;
	for (auto m : map2)
	{
		if (map1[m.first] > 0)
			hap += max(map1[m.first], m.second);
		else hap += m.second;
	}
	if (hap == 0)return 65536;
	return (int)(gyo / (double)hap * 65536);
}