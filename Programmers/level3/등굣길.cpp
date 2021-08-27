#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    set<pair<int, int>> puddle;

    int size = puddles.size();
    for (int i = 0; i < size; ++i)
        puddle.insert({ puddles[i][0], puddles[i][1] });

    dp[1][1] = 1;
    int k = 1000000007;
    auto endIter = puddle.end();
    for (int i = 1; i <= m; ++i)
    {
        for (int j = i == 1 ? 2 : 1; j <= n; ++j)
        {
            if (puddle.find({ i, j }) == endIter)
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % k;
        }
    }
    return dp[m][n];
}