#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> map;
    for (auto cloth : clothes)
    {
        map[cloth[1]]++;
    }
    for (unordered_map<string, int>::iterator iter = map.begin(); iter != map.end(); ++iter)
    {
        answer *= iter->second + 1;
    }
    return answer - 1;
}