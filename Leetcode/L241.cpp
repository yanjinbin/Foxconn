#include <algorithm>
#include <climits>
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
private:
  vector<int> nums;
  vector<char> ops;
  vector<int> dp[21][21];

public:
  vector<int> diffWaysToCompute(string expr) {
    for (int i = 0; i < expr.size(); i++) {
      int j = i;
      while (j < expr.size() && isdigit(expr[j])) {
        j++;
      }
      nums.PB(stoi(expr.substr(i, j - i)));
      if (j < expr.size())
        ops.PB(expr[j]);
      i = j; // 别忘记更新j
    }

    int n = nums.size();
    helper(0, n - 1); // 递归 top-down方式
    return dp[0][n - 1];
    // bottom-up方式
    /*
        for (int i = 0; i < n; i++) {
          dp[i][i] = {nums[i]};
        }
        for (int len = 2; len <= n; len++) {
          for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++) {
              for (auto x : dp[i][k]) {
                for (auto y : dp[k + 1][j]) {
                  if (ops[k] == '+') dp[i][j].PB(x + y);
                  if (ops[k] == '-') dp[i][j].PB(x - y);
                  if (ops[k] == '*') dp[i][j].PB(x * y);
                }
              }
            }
          }
        }
        return dp[0][n - 1];
    */
  }

  // 递归方式
  void helper(int lo, int hi) {
    if (!dp[lo][hi].empty())
      return;
    if (lo == hi)
      dp[lo][hi] = {nums[lo]};
    for (int i = lo; i < hi; i++) {
      helper(lo, i);
      helper(i + 1, hi);
      for (auto x : dp[lo][i]) {
        for (auto y : dp[i + 1][hi]) {
          if (ops[i] == '+')
            dp[lo][hi].PB(x + y);
          if (ops[i] == '-')
            dp[lo][hi].PB(x - y);
          if (ops[i] == '*')
            dp[lo][hi].PB(x * y);
        }
      }
    }
  }
};