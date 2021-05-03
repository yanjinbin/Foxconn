#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <stack>
#include <cmath>

using namespace std;

const int INF = 0x3F3F3F3F, MAX_VALUE = 0x7FFFFFFF, MIN_VALUE = 0x80000000, MOD = 1E9 + 7;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define debug puts("pigtoria bling bling ⚡️⚡️");
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define LL long long
#define LD long double
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second


class Solution {
public:
    int minDistance(string s, string t) {
        int m = s.size(), n = t.size();
        if (n * m == 0) return n + m;
        vector <vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1])dp[i][j] = dp[i - 1][j - 1];
                else {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
                }

            }
        }
        return dp[m][n];
    }

    int minDistance_(string s1, string s2) {
        int N1 = s1.length();
        int N2 = s2.length();
        vector <vector<int>> memo(N1, vector<int>(N2));
        return dfs(s1, 0, s2, 0, memo);
    }

    int dfs(string s1, int i, string s2, int j, vector<vector<int>> memo) {
        if (j == s2.size()) return s1.size() - i;
        if (i == s1.size()) return s2.size() - j;
        if (memo[i][j] > 0) return memo[i][j];
        if (s1[i] == s2[j]) {
            return dfs(s1, i + 1, s2, j + 1, memo);
        } else {
            int insertCnt = dfs(s1, i, s2, j + 1, memo);
            int deleteCnt = dfs(s1, i + 1, s2, j, memo);
            int replaceCnt = dfs(s1, i + 1, s2, j + 1, memo);
            memo[i][j] = min(insertCnt, min(deleteCnt, replaceCnt)) + 1;
        }
        return memo[i][j];
    }
};