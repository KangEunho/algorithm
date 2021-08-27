#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.begin(), people.end());
    int len = people.size();
    int i, j;
    for (i = 0, j = len - 1; i < j;)
    {
        if (people[i] + people[j] > limit)
        {
            answer++; --j;
        }
        else
        {
            answer++; ++i; --j;
        }
    }
    if (j == i)
        answer++;

    return answer;
}