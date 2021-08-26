#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    bool lotto[47] = { false };
    for (int i = 0; i < win_nums.size(); ++i)
        lotto[win_nums[i]] = true;

    int count = 0, zeroCount = 0;
    for (int i = 0; i < lottos.size(); ++i)
    {
        if (lottos[i] == 0)zeroCount++;
        else if (lotto[lottos[i]])count++;
    }

    answer.push_back(min(6, 6 - (count + zeroCount) + 1));
    answer.push_back(min(6, 6 - count + 1));
    return answer;
}