#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    const int n = board.size();
    vector<int> height(n, n);
    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < n; ++x)
        {
            if (height[x] != n)continue;
            if (board[y][x] > 0)
            {
                height[x] = y;
            }
        }
    }

    stack<int> stack;
    const int moveSize = moves.size();
    for (int i = 0; i < moveSize; ++i)
    {
        int x = moves[i] - 1;
        if (height[x] < n)
        {
            int item = board[height[x]++][x];
            if (stack.empty() == false)
            {
                int topitem = stack.top();
                if (item == topitem)
                {
                    stack.pop();
                    answer += 2;
                }
                else
                    stack.push(item);
            }
            else
                stack.push(item);
        }
    }
    return answer;
}