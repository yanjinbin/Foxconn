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

// special state dp学习
//  1659 1595  1799 1931 1944 1866  1411
// 465 691 943  1655 1494
class Solution {
public:
  // 465 https://bit.ly/3woUmfM
  int minTransfers(vector<vector<int>> &transactions) {
    unordered_map<int, int> balance;
    for (auto &t : transactions) {
      balance[t[0]] += t[2];
      balance[t1] -= [t2];
    }
    vectot<int> nums;
    for (auto x : balance) {
      nums.PB(x.second);
    }
    int n = nums.size();
    vector<int> sum(1 << n, 0);
    for (int state = 0; state < (1 << n); state++) {
      for (int i = 0; i < n; i++) {
        if ((state >> i) & 1) {
          sum[state] += nums[i];
        }
      }
    }

    vector<int> dp(1 << n, INF);
    for (int state = 0; state < (1 << n); state++) {
      if (sum[state] != 0)
        continue;
      dp[state] = __builtin_popcount(state) - 1;
      for (int sub = state - 1; sub > 0; sub = (sub - 1) & state) {
        if (sum[sub] == 0) {
          dp[state] = min(dp[state], dp[sub] + dp[state - sub]);
        }
      }
    }
    return dp[(1 << n) - 1];
  }

  // 691
  int minStickers(vector<string> &stickers, string target) {
    int n = stickers.size(), m = target.size();
    vector<vector<int>> cnt(n, vector<int>(26));
    for (int i = 0; i < n; i++)
      for (char c : stickers[i])
        cnt[i][c - 'a']++;

    vector<int> dp(1 << m, INF);
    dp[0] = 0;
    for (int state = 0; state < (1 << m); state++) {
      if (dp[state] == INF)
        continue;
      for (int k = 0; k < n; k++) {
        int nxt = state;
        vector<int> left(cnt[k]);
        for (int j = 0; j < m; j++) {
          if (nxt & (1 << j)) // (nxt & (1 << j))  代表2的N次方 不是 1  写成右边这样就可以 判定是不是指定J位是1 //
                              // (((nxt >> j)&1 )== 1)
            continue; // 1 代表已经有了
          if (left[target[j] - 'a'] > 0) {
            nxt += (1 << j);
            left[target[j] - 'a']--;
          }
        }
        dp[nxt] = min(dp[nxt], dp[state] + 1);
      }
    }
    return dp[(1 << m) - 1] == INF ? -1 : dp[(1 << m) - 1];
  }

  // 1494 https://prnt.sc/1zp3hor  https://youtu.be/g2jmxEzwtv0?t=838
  int minNumberOfSemesters(int n, vector<vector<int>> &relations, int k) {
    vector<int> prevCourse(n, 0);
    vector<int> prereq(1 << n, 0);
    vector<int> dp(1 << n, INT_MAX / 2);

    for (auto x : relations) {
      prevCourse[x[1] - 1] |= (1 << (x[0] - 1)); // 0-index
    }
    // dp init 第一个学期
    for (int state = 0; state < (1 << n); state++) {

      for (int i = 0; i < n; i++) {
        if ((state >> i) & 1)
          prereq[state] |= prevCourse[i];
      }
      if (prereq[state] == 0 && (__builtin_popcount(state) <= k)) {
        dp[state] = 1;
      }
    }

    for (int state = 0; state < (1 << n); state++) {
      for (int subset = state; subset > 0; subset = (subset - 1) & state) {
        if (__builtin_popcount(state) - __builtin_popcount(subset) <= k &&
            ((subset & prereq[state]) == prereq[state])) {
          dp[state] = min(dp[state], dp[subset] + 1);
        }
      }
    }
    return dp[(1 << n) - 1];
  }

  // 1655 经典状态压缩, dp[i][state] i表示前i个满足state
  bool canDistribute(vector<int> &nums, vector<int> &quantity) {
    unordered_map<int, int> map;
    for (auto x : nums)
      map[x]++;
    vector<int> count;
    for (auto x : map)
      count.push_back(x.second);

    int N = count.size();
    int M = quantity.size();
    count.insert(count.begin(), 0);

    vector<vector<bool>> dp(N + 1, vector<bool>(1 << M));
    dp[0][0] = true;
    for (int i = 0; i <= N; i++) {
      dp[i][0] = true;
    }
    // T: N * 3的M次方
    for (int i = 1; i <= N; i++) {
      for (int state = 1; state < (1 << M); state++) {
        if (dp[i - 1][state] == true)
          dp[i][state] = true;
        for (int subset = state; subset > 0; subset = (subset - 1) & state) {
          if (dp[i - 1][state - subset] == false)
            continue;
          if (satisfy(count[i], quantity, subset)) {
            dp[i][state] = true;
            break;
          }
        }
      }
    }
    return dp[N][(1 << M) - 1];
  }

  bool satisfy(int count, vector<int> &quantity, int subset) {
    int M = quantity.size();
    int sum = 0;
    for (int i = 0; i < M; i++) {
      if ((subset >> i) & 1) {
        sum += quantity[i];
      }
    }
    return sum <= count;
  }

  // 1595
  // dp[i][state] <-dp[i-1][state-subset]
  // dp[i][state]<-dp[i-1][state] , visited pointed
  int connectTwoGroups(vector<vector<int>> &cost) {
    int m = cost.size();
    int n = cost[0].size();
    vector<vector<int>> dp(m, vector<int>(1 << n, INF));
    // init i=0;
    for (int state = 1; state < (1 << n); state++) { // state 从 1开始
      int sum = 0;
      for (int j = 0; j < n; j++) {
        if (((state >> j) & 1) == 1) {
          sum += cost[0][j];
        }
      }
      dp[0][state] = sum;
    }

    for (int i = 1; i < m; i++) {
      for (int state = 0; state < (1 << n); state++) {

        for (int subset = state; subset > 0; subset = (subset - 1) & state) {
          // 遍历1
          int sum = 0;
          for (int j = 0; j < n; j++)
            if ((subset >> j) & 1)
              sum += cost[i][j];
          dp[i][state] = min(dp[i][state], dp[i - 1][state - subset] + sum);
        }
        int minPath = INF;
        for (int j = 0; j < n; j++)
          minPath = min(minPath, cost[i][j]);
        dp[i][state] = min(dp[i][state], dp[i - 1][state] + minPath);
      }
    }
    return dp[m - 1][(1 << n) - 1];
  }

  // 1986

  // 1994

  // 943  super-hard
  string shortestSuperstring(vector<string> &words) {}
}