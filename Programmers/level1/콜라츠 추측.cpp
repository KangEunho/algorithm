#include <string>
#include <vector>

using namespace std;

int solution(int num) {
	if (num == 1)
		return 0;
	int answer = 0;
	long long lnum = num;
	while (answer < 500)
	{
		answer++;
		lnum = (lnum & 1 == 1) ? lnum * 3 + 1 : lnum / 2;
		if (lnum == 1)
			return answer;
	}
	return -1;

}