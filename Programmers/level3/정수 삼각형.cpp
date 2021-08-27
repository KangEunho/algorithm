#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int size = triangle.size();
    vector<vector<int>> d(size);
    for (int i = 0; i < size; ++i)
        d[i] = vector<int>(size);

    d[0][0] = triangle[0][0];
    for (int i = 1; i < size; ++i)
    {
        int curSize = triangle[i].size();
        for (int j = 0; j < curSize; ++j)
        {
            int val1 = 0, val2 = 0;
            if (j != 0)val1 = d[i - 1][j - 1];
            if (j != curSize - 1)val2 = d[i - 1][j];
            d[i][j] = max(val1, val2) + triangle[i][j];
        }
    }
    int bottomSize = triangle[size - 1].size();
    for (int i = 0; i < bottomSize; ++i)
    {
        answer = max(answer, d[size - 1][i]);
    }
    return answer;
}