#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {

    vector<bool> loster(n + 1);
    for (int i = 0; i < lost.size(); ++i)
    {
        loster[lost[i]] = true;
    }
    vector<bool> reserver(n + 1);
    for (int i = 0; i < reserve.size(); ++i)
    {
        if (loster[reserve[i]])
            loster[reserve[i]] = false;
        else
            reserver[reserve[i]] = true;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (loster[i])
        {
            if (i - 1 >= 0 && reserver[i - 1])
            {
                loster[i] = false;
                reserver[i - 1] = false;
            }
            else if (i + 1 <= n && reserver[i + 1])
            {
                loster[i] = false;
                reserver[i + 1] = false;
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (loster[i])
            answer++;
    }
    return n - answer;
}