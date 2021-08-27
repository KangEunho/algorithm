#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Music
{
    int index, plays;
};
bool MusicCmp(const Music& m1, const Music& m2)
{
    return m1.plays > m2.plays;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, vector<Music>> map;

    const int size = genres.size();
    for (int i = 0; i < size; ++i)
    {
        Music music;
        music.index = i;
        music.plays = plays[i];
        map[genres[i]].push_back(music);
    }

    vector<int> answer;
    while (map.empty() == false)
    {
        string key;
        int max = -1;
        for (auto iter : map)
        {
            int sum = 0;
            for (auto music : iter.second)
            {
                sum += music.plays;
            }

            if (sum > max)
            {
                max = sum;
                key = iter.first;
            }
        }

        sort(map[key].begin(), map[key].end(), MusicCmp);

        int vSize = map[key].size();
        int size = min(2, vSize);
        for (int i = 0; i < size; ++i)
        {
            answer.push_back(map[key][i].index);
        }

        map.erase(key);
    }
    return answer;
}