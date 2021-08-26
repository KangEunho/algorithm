#include <string>
#include <vector>
#include <math.h>
using namespace std;

bool isOddnumYaksu(int n)
{
	double sqrtN = sqrt(n);
	if (abs((int)sqrtN - sqrtN) < 2.2204460492503131e-016)
		return true;

	return false;
}
int solution(int left, int right) {
	int answer = 0;
	for (int i = left; i <= right; ++i)
	{
		answer += isOddnumYaksu(i) ? -i : i;
	}
	return answer;
}