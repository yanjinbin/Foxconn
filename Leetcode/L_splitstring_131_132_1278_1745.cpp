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
#define ready ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define debug puts("⚡️⚡️bling bling ⚡️⚡️");
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define pii pair<int, int>
#define LL long long
#define LD long double
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second

// 分割回文串
// tag: dp套dp
//   131_132_1278_1745
class Solution {
public:
  // 1278 dp套dp 区间型DP
  int palindromePartition(string s, int k) {
    int N = s.size();
    s = "#" + s;
    int K = k;
    vector<vector<int>> count(N + 1, vector<int>(N + 1, 0));
    // init 预先计算 change次数
    for (int i = 1; i <= N; i++) {
      count[i][i] = 0;
    }
    for (int len = 2; len <= N; len++) {
      for (int i = 1; i + len - 1 <= N; i++) {
        int j = i + len - 1;
        if (s[i] == s[j])
          count[i][j] = count[i + 1][j - 1];
        else
          count[i][j] = count[i + 1][j - 1] + 1;
      }
    }

    vector<vector<int>> dp(N + 1, vector<int>(K + 1, INF));
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
      for (int k = 1; k <= K; k++) {
        for (int j = k; j <= i; j++) {
          dp[i][k] = min(dp[i][k], dp[j - 1][k - 1] + count[j][i]);
        }
      }
    }
    return dp[N][K];
  }

  // 131
  vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> sub;
    function<void(int)> dfs = [&](int cur) {
      if (cur == s.size()) {
        ans.push_back(sub);
        return;
      }
      for (int i = cur; i < s.size(); i++) {
        if (isPal(s, cur, i)) {
          sub.push_back(s.substr(cur, i - cur + 1));
          dfs(i + 1);
          sub.pop_back();
        }
      }
    };
    dfs(0);
    return ans;
  }

  bool isPal(string s, int l, int r) {
    while (l < r) {
      if (s[l++] != s[r--])
        return false;
    }
    return true;
  }

  // 132
  int minCut(string s) {
    int n = s.size();
    /* // 不写成这样,是因为 len =2 时候 valid[0][1]= false了 , string =aab 因为valid[1][0] 是false
    vector<vector<bool>> valid(n, vector<bool>(n, true));
    for(int i=0;i<n;i++){
      valid[i][i]=true;
    }

    for (int len = 2; len <= n; len++) {
      for (int i = 0; i + len - 1 < n; i++) {
        int j = i+len-1;
        if(s[i]==s[j] && valid[i+1][j-1]){
          valid[i][j] = true;
        }
      }
    }*/

    vector<vector<bool>> valid(n, vector<bool>(n, true));
    for (int len = 2; len <= n; len++) {
      for (int i = 0, j = i + len - 1; i + len - 1 < n; i++, j++) {
        valid[i][j] = s[i] == s[j] && valid[i + 1][j - 1];
      }
    }
    vector<int> dp(n, n);
    for (int i = 0; i < n; i++) {
      if (valid[0][i]) {
        dp[i] = 0;
        continue;
      }
      for (int j = 0; j < i; j++) {
        if (valid[j + 1][i]) {
          dp[i] = min(dp[i], dp[j] + 1);
        }
      }
    }
    return dp[n - 1];
  }

  // 1745  马拉车算法
  bool checkPartitioning(string s) {
    int n = s.size();
    vector<vector<bool>> valid(n, vector<bool>(n, true));
    for (int len = 2; len <= n; len++) {
      for (int i = 0, j = i + len - 1; i + len - 1 < n; i++, j++) {
        valid[i][j] = s[i] == s[j] && valid[i + 1][j - 1];
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = i + 2; j < n; j++) {
        if (valid[0][i] && valid[i + 1][j - 1] && valid[j][n - 1]) {
          return true;
        }
      }
    }
    return false;
  }
};
