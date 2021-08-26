#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    unordered_map<string, int> map;
    int size = participant.size();

    for (string name : participant)
    {
        unordered_map<string, int>::iterator iter = map.find(name);
        if (iter == map.end())
            map.insert(make_pair(name, 1));
        else
            map[name]++;
    }

    for (string name : completion)
    {
        unordered_map<string, int>::iterator iter = map.find(name);
        iter->second--;
        if (iter->second == 0)
            map.erase(iter);
    }
    return map.begin()->first;
}