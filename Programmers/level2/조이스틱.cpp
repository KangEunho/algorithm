#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;

    int sLen = name.length();
    for (int i = 0; i < sLen; ++i)
    {
        if (name[i] != 'A')
        {
            int n1 = name[i] - 'A';
            int n2 = 'Z' - name[i] + 1;
            answer += min(n1, n2);
        }
    }
    int move = sLen - 1;
    for (int i = 0; i < sLen - 1; ++i)
    {
        int next = i + 1;
        while (name[next] == 'A') next++;
        int left = i;
        int right = sLen - next;
        move = min(move, left + right + min(left, right));
    }
    answer += move;

    return answer;
}