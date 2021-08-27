#include <iostream>
#include<vector>
using namespace std;

int solution(vector<vector<int>> board)
{
	int col = board.size();
	int row = board[0].size();
	int answer = 0;

	if (col == 1)
	{
		for (int x = 0; x < row; ++x)
			if (board[0][x] == 1)
				return 1;
	}
	if (row == 1)
	{
		for (int y = 0; y < col; ++y)
			if (board[y][0] == 1)
				return 1;
	}

	for (int y = 1; y < col; ++y)
	{
		for (int x = 1; x < row; ++x)
		{
			if (board[y][x] == 1)
			{
				board[y][x] = 1 + min(board[y][x - 1], min(board[y - 1][x - 1], board[y - 1][x]));
				answer = max(answer, board[y][x]);
			}
		}
	}

	return answer * answer;
}