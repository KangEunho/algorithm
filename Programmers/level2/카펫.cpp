#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red)
{
    vector<int> answer;
    int tileCount = brown + red;
    for (int i = 3; ; ++i)
    {
        if (tileCount % i == 0)
        {
            int r = tileCount / i;
            if (r + r + i + i - 4 == brown)
            {
                answer.push_back(r);
                answer.push_back(i);
                break;
            }
        }
    }
    return answer;
}