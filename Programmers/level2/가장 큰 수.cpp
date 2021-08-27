#include <string>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(const string& a, const string& b)
{
    return a + b > b + a;
}
string solution(vector<int> numbers) {
    string answer = "";
    int size = numbers.size();
    vector<string> v(size);

    for (int i = 0; i < size; ++i)
        v[i] = to_string(numbers[i]);

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < size; ++i)
        answer += v[i];

    if (answer[0] == '0')
        answer = "0";

    return answer;
}