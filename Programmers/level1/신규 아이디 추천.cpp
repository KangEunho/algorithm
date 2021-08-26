#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    for (int i = 0; i < new_id.length(); ++i)
    {
        new_id[i] = tolower(new_id[i]);
        char c = new_id[i];
        if (!(c >= 'a' && c <= 'z') && !(c >= '0' && c <= '9') && c != '-' && c != '_' && c != '.')
        {
            new_id.erase(i, 1);
            --i;
        }
    }
    for (int i = 1; i < new_id.length(); ++i)
    {
        char c = new_id[i];
        if (c == '.' && new_id[i - 1] == '.')
        {
            new_id.erase(i, 1);
            --i;
        }
    }
    if (new_id.length() > 0)
    {
        if (new_id[0] == '.')
            new_id.erase(0, 1);
    }
    if (new_id.length() > 0)
    {
        if (new_id[new_id.length() - 1] == '.')
            new_id.erase(new_id.length() - 1, 1);
    }
    if (new_id.length() == 0)
        new_id = "a";
    if (new_id.length() >= 16)
    {
        new_id.erase(new_id.begin() + 15, new_id.end());
        if (new_id.length() > 0)
        {
            if (new_id[new_id.length() - 1] == '.')
                new_id.erase(new_id.length() - 1, 1);
        }
    }
    while (new_id.length() < 3)
        new_id.push_back(new_id[new_id.length() - 1]);
    return new_id;
}