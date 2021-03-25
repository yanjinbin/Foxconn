
#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include <stack>

using namespace std;

const int INF = 0x3F3F3F3F;
const int MOD = 1E9 + 7;
#define ready ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define debug puts("pigtoria bling bling ⚡️⚡️");
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define pii pair<int, int>
#define LL long long
#define LD long double
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second

// https://youtu.be/Uk9JRbylA0c
class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        s1 = "#" + s1, s2 = "#" + s2;// 这是一个很好的设计点🌟⭐
        auto dp = vector < vector < int >> (m + 1, vector<int>(n + 1));
        for (int i = 0; i <= m; ++i) dp[i][0] = i;
        for (int j = 0; j <= n; ++j) dp[0][j] = j;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                }
            }
        }
        int i = m, j = n;
        string ans;
        while (i > 0 && j > 0) {
            if (s1[i] == s2[j]) {
                ans.PB(s1[i]);
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                ans.PB(s2[j]);
                j--;
            } else {
                ans.PB(s1[i]);
                i--;
            }
        }
        while (i > 0) {
            ans.PB(s1[i--]);
        }
        while (j > 0) {
            ans.PB(s2[j--]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};