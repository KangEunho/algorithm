#include <string>
using namespace std;

int solution(string dirs) {
	int dir_val[4] = { 1, 2, 4, 8 }; // UDRL
	int d[11][11] = { 0 };

	int answer = 0;
	int x = 5, y = 5;
	for (int i = 0; i < dirs.length(); ++i)
	{
		if (dirs[i] == 'U')
		{
			if (y + 1 > 10)continue;
			if ((d[x][y] & dir_val[0]) == 0)
			{
				answer++;
				d[x][y] |= dir_val[0];
				d[x][y + 1] |= dir_val[1];
			}
			y += 1;
		}
		else if (dirs[i] == 'D')
		{
			if (y - 1 < 0)continue;
			if ((d[x][y] & dir_val[1]) == 0)
			{
				answer++;
				d[x][y] |= dir_val[1];
				d[x][y - 1] |= dir_val[0];
			}
			y -= 1;
		}
		else if (dirs[i] == 'R')
		{
			if (x + 1 > 10)continue;
			if ((d[x][y] & dir_val[2]) == 0)
			{
				answer++;
				d[x][y] |= dir_val[2];
				d[x + 1][y] |= dir_val[3];
			}
			x += 1;
		}
		else if (dirs[i] == 'L')
		{
			if (x - 1 < 0)continue;
			if ((d[x][y] & dir_val[3]) == 0)
			{
				answer++;
				d[x][y] |= dir_val[3];
				d[x - 1][y] |= dir_val[2];
			}
			x -= 1;
		}
	}
	return answer;
}