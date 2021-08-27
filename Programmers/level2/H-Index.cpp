#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<int>());

    const int size = citations.size();
    bool trigger = false;
    for (int i = 0; i < size; i++)
    {
        if (citations[i] < i + 1)
        {
            answer = i;
            trigger = true;
            break;
        }
    }
    if (!trigger)
        answer = size;
    return answer;
}