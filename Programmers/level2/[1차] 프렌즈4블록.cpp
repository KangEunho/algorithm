#include <string>
#include <vector>

using namespace std;

int remove(int m, int n, vector<string>& board)
{
	vector <vector<bool>> check(m, vector<bool>(n, false));
	int cnt = 0;
	for (int y = 0; y < m - 1; ++y)
	{
		for (int x = 0; x < n - 1; ++x)
		{
			char val = board[y][x];
			if (val == ' ')
				continue;
			bool remove = true;
			for (int i = 0; i < 2; ++i)
			{
				if (remove == false)
					break;
				for (int j = 0; j < 2; ++j)
				{
					if (board[y + i][x + j] != val)
					{
						remove = false;
						break;
					}
				}
			}
			if (remove)
			{
				for (int i = 0; i < 2; ++i)
				{
					for (int j = 0; j < 2; ++j)
					{
						if (check[y + i][x + j] == false)
						{
							check[y + i][x + j] = true;
							cnt++;
						}
					}
				}
			}
		}
	}
	for (int y = 0; y < m; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			if (check[y][x])
			{
				board[y][x] = ' ';
			}
		}
	}
	return cnt;
}
void drop(int m, int n, vector<string>& board)
{
	for (int x = 0; x < n; ++x)
	{
		int whiteSpace = 0;
		for (int y = m - 1; y >= 0; --y)
		{
			if (board[y][x] == ' ')
				whiteSpace++;
			else if (whiteSpace > 0)
			{
				board[y + whiteSpace][x] = board[y][x];
				board[y][x] = ' ';
			}
		}
	}
}
int solution(int m, int n, vector<string> board) {
	int answer = 0;
	while (true)
	{
		int res = remove(m, n, board);
		if (res == 0)break;
		answer += res;
		drop(m, n, board);
	}
	return answer;
}