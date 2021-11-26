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

class Solution {
public:
  // 410
  int splitArray_01(vector<int> &nums, int m) {
    int n = nums.size();
    vector<int> sum(n);
    sum[0] = nums[0];
    for (int i = 1; i < n; i++) {
      sum[i] = sum[i - 1] + nums[i];
    }
    vector<vector<int>> dp(m + 1, vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
      dp[1][i] = sum[i];
    }

    for (int i = 2; i <= m; i++) {
      for (int j = i - 1; j < n; j++) {
        for (int k = 0; k < j; k++) {
          dp[i][j] = min(dp[i][j], max(dp[i - 1][k], sum[j] - sum[k]));
        }
      }
    }
    return dp[m][n - 1];
  }

  // binary-search  算法推导 https://youtu.be/_k-Jb4b7b_0?t=933
  int splitArray_02(vector<int> &nums, int m) {
    long lo = *max_element(nums.begin(), nums.end());
    long hi = accumulate(nums.begin(), nums.end()) + 1;
    while (lo < hi) {
      long mid = (hi - lo) / 2 + lo;
      if (groups(nums, mid) > m) { // k > m
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }
    return lo;
  }
  int groups(vector<int> &nums, long limit) {
    long sum = 0;
    int groups = 1;
    for (auto x : nums) {
      if (sum + x > limit) {
        sum = x;
        groups++;
      } else {
        sum += x;
      }
    }
    return groups;
  }
  // 1011 和 410 一模一样
  int shipWithinDays(vector<int> &weights, int days) {
    long lo = *max_element(weights.begin(), weights.end());
    long hi = accumulate(weights.begin(), weights.end(), 0L) + 1;
    while (lo < hi) {
      long mid = (hi - lo) / 2 + lo;
      if (groups(weights, mid) > days) { // k > m
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }
    return lo;
  }
};