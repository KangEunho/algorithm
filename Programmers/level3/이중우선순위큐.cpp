#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {

    priority_queue<int, vector<int>, greater<>> minQueue;
    priority_queue<int, vector<int>, less<>> maxQueue;

    const int size = operations.size();
    int qSize = 0;
    for (int i = 0; i < size; ++i)
    {
        int value = stoi(operations[i].substr(1, operations[i].length()));
        if (operations[i][0] == 'I')
        {
            qSize++;
            minQueue.push(value);
            maxQueue.push(value);
        }
        else
        {
            if (qSize == 0)
                continue;
            if (value == 1)
            {
                maxQueue.pop();
            }
            else
            {
                minQueue.pop();
            }

            if (--qSize == 0)
            {
                while (maxQueue.empty() == false)
                    maxQueue.pop();
                while (minQueue.empty() == false)
                    minQueue.pop();
            }
        }
    }
    vector<int> answer(2);

    if (qSize > 1)
    {
        answer[0] = maxQueue.top();
        answer[1] = minQueue.top();
    }

    return answer;
}