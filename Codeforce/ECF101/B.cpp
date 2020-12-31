#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
string path = "/Users/hakunamatata/CLionProjects/Foxconn/Codeforce/";
const int INF = 0x3F3F3F3F;

class Solution {
  // T: O(N*M)
 public:
  int solve(vector<int> p, vector<int> q) {
    int n = p.size(), m = q.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -INF));
    dp[0][0] = 0;
    int ans = 0;
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        if (i < n) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + p[i]);
        if (j < m) dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + q[j]);
        ans = max(ans, dp[i][j]);
      }
    }
    return ans;
  }
  // T: O(N+M)
  int solve_(vector<int> p, vector<int> q) {
    partial_sum(p.begin(), p.end(), p.begin());
    partial_sum(q.begin(), q.end(), q.begin());
    return max(0, *max_element(p.begin(), p.end())) +max(0, *max_element(q.begin(), q.end()));
  }
  // error
  int solve_err(vector<int> p, vector<int> q) {
    int n = p.size(), m = q.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -INF));
    // INIT
    dp[0][0] = 0;
    for (int i = 1; i <= m; i++) {
      dp[0][i] = max(dp[0][i - 1], dp[0][i - 1] + q[i - 1]);
    }
    for (int i = 1; i <= n; i++) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][0] + p[i - 1]);
    }
    // tran
    for (int i = 1; i < n + 1; i++) {
      for (int j = 1; j < m + 1; j++) {
        dp[i][j] = max(dp[i][j - 1], dp[i][j - 1] + q[j - 1]);
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j] + p[i - 1]);
      }
    }
    return dp[n][m];
  }
};
// 测试数据
int main() {
  int T;
  cin >> T;
  Solution INSTANCE;
  while (T--) {
    int n, m, val;
    vector<int> a, b;
    cin >> n;
    while (n--) {
      cin >> val;
      a.emplace_back(val);
    }
    cin >> m;
    while (m--) {
      cin >> val;
      b.emplace_back(val);
    }
    int ans = INSTANCE.solve(a, b);
    cout << ans << endl;
  }
  return 0;
}
