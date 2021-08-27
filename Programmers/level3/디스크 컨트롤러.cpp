#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool JobCmp(const vector<int>& v1, const vector<int>& v2)
{
    if (v1[0] == v2[0])
        return v1[1] < v2[1];
    return v1[0] < v2[0];
}

struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
};
int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end(), JobCmp);

    int answer = 0;
    int time = 0;
    priority_queue<vector<int>, vector<vector<int>>, cmp> q;

    const int size = jobs.size();
    int i = 0;
    while (i < size || q.empty() == false)
    {
        while (i < size && time >= jobs[i][0])
        {
            q.push(jobs[i++]);
        }

        if (q.empty() == false)
        {
            auto top = q.top();
            q.pop();
            time += top[1];
            answer += time - top[0];
        }
        else if (i < size)time = jobs[i][0];
    }

    return answer / size;
}