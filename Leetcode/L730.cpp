
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int MAX_VALUE = 0x7FFFFFFF, MIN_VALUE = 0x80000000, INF = 0x3F3F3F3F;
const long kMod = 1e9 + 7;
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define debug puts("⚡️⚡️");
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define pii pair<int, int>
#define LL long long
#define LD long double
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second

// dp[i,j] =dp[x,y] s[i]==s[j]
// 这道题目还是非常有意思得, 可以让你删去任意字符
// 解题参考链接: https://bit.ly/3MTc3dS
class Solution {
public:
  int countPalindromicSubsequences(string s) {
    int n = s.length();
    auto dp = vector<vector<int>>(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
      dp[i][i] = 1;
    for (int len = 2; len <= n; len++) {
      for (int i = 0; i + len - 1 < n; i++) {
        const int j = i + len - 1;
        if (s[i] == s[j]) {
          int l = i + 1, r = j - 1;
          while (l <= r && s[l] != s[i])
            l++;
          while (l <= r && s[r] != s[i])
            r--;
          if (l == r)
            dp[i][j] = 2 * dp[i + 1][j - 1] + 1;
          // 存在可以剪切的部分,减去overlap部分
          else if (l < r)
            dp[i][j] = 2 * dp[i + 1][j - 1] - dp[l + 1][r - 1];
          // 不存在可以剪切的部分 暨 i=l,j=r
          else
            dp[i][j] = 2 * dp[i + 1][j - 1] + 2;
        } else {
          dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
        }
        dp[i][j] = (dp[i][j] + kMod) % kMod;
      }
    }
    return dp[0][n - 1];
  }
};