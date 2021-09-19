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
    int ans;

    int minDistance_(string s, string t) {
        int m = s.size(), n = t.size();
        vector <vector<int>> cache(m, vector<int>(n, -1));
        return dfs(s, 0, t, 0, cache);
    }

    int dfs(string s, int i, string t, int j, vector<vector<int>> cache) {
        if (j == t.size()) return s.size() - i;//删除操作次数
        if (i == s.size()) return t.size() - j;// 添加操作次数
        if (cache[i][j] > 0) return cache[i][j];
        if (s[i] == t[j]) {
            return dfs(s, i + 1, t, j + 1, cache);
        } else {
            int insCnt = dfs(s, i, t, j + 1, cache);
            int delCnt = dfs(s, i + 1, t, j, cache);
            int repCnt = dfs(s, i + 1, t, j + 1, cache);
            cache[i][j] = min(insCnt, min(delCnt, repCnt)) + 1;
        }
        return cache[i][j];
    }

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
};

int main() {
    fastio
    int N, M;
    string s, t;
    cin >> N >> s;
    cin >> M >> t;
    Solution INSTANCE;
    int ans = INSTANCE.minDistance(s, t);
    cout << ans << endl;
    return 0;
}

