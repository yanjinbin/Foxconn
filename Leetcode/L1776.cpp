#include <algorithm>
#include <cmath>
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
const int MAX_VALUE = 0x7FFFFFFF, MIN_VALUE = 0x80000000, INF = 0x3F3F3F3F, kMod = 1E9 + 7;
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
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

// tag: 区间 dp
// xx[x]0000[x]xx
//    i      j
// dp[i][j]=dp[i-1][j]+nums[i]*mult[i+j] ,  dp[i][j-1]+nums[n-j+1]*mult[i+j]， i
class Solution {
public:
  int maximumScore(vector<int> &nums, vector<int> &multipliers) {
    int n = nums.size();
    int m = multipliers.size();
    auto dp = vector<vector<int>>(m + 1, vector<int>(m + 1, -INF));
    nums.insert(nums.begin(), 0);
    dp[0][0] = 0;
    int ans = -INF;
    for (int len = 1; len <= m; ++len) {
      for (int i = 0; i <= len; ++i) {
        int j = len - i;
        if (i >= 1) {
          dp[i][j] = max(dp[i][j], dp[i - 1][j] + nums[i] * multipliers[len - 1]);
        }
        if (j >= 1) {
          dp[i][j] = max(dp[i][j], dp[i][j - 1] + nums[n - j + 1] * multipliers[len - 1]);
        }
        if (len == m) {
          ans = max(ans, dp[i][j]);
        }
      }
    }
    return ans;
  }

};