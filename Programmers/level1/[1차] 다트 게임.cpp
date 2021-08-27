#include <string>
#include <vector>
#include <math.h>
using namespace std;

int solution(string dartResult) {
	const int sLen = dartResult.length();
	vector<int> score;
	int prevScoreIndex = 0;
	for (int i = 0; i < sLen; ++i)
	{
		char c = dartResult[i];
		if (c >= '0' && c <= '9')
		{
			if (prevScoreIndex == i - 1)
				score[score.size() - 1] = 10;
			else
				score.push_back(c - '0');
			prevScoreIndex = i;
		}
		else if (c == 'D')
			score[score.size() - 1] = pow(score[score.size() - 1], 2);
		else if (c == 'T')
			score[score.size() - 1] = pow(score[score.size() - 1], 3);
		else if (c == '*')
		{
			score[score.size() - 1] *= 2;
			if (score.size() >= 2)
				score[score.size() - 2] *= 2;
		}
		else if (c == '#')
			score[score.size() - 1] *= -1;
	}
	int answer = 0;
	for (int i = 0; i < score.size(); ++i)
		answer += score[i];
	return answer;
}