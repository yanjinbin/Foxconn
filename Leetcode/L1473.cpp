#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

//  粉刷房子3 https://youtu.be/53b32Upplk0
// 状态转移方程式 https://zxi.mytechroad.com/blog/wp-content/uploads/2020/06/1473-ep333.png
//  dp(k,i,ci) = min(dp(k,i,ci), dp(k-1,i-1,cj)+cost[i-1][ci-1])  if ci != cj and
//  dp(k,i,ci) = min(dp(k,i,ci),dp(k,i-1,cj)+cost[i-1][ci-1] if(ci==cj)
// min(dp[target][m][*])
class Solution {
public:
    int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target) {
        int INF = 0x3F3F3F, s = 1;
        // INIT
        vector<vector<vector<int>>> dp(target + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, INF)));
        fill(begin(dp[0][0]), end(dp[0][0]), 0);
        // transit
        for (int k = 1; k <= target; k++) {
            for (int i = k; i <= m; i++) {// i从k开始 优化
                int hi = houses[i - 1];
                int hj = i >= 2 ? houses[i - 2] : 0;
                const auto &[si, ei] = hi ? tie(hi, hi) : tie(s, n);// 为什么必须要加上const
                const auto &[sj, ej] = hj ? tie(hj, hj) : tie(s, n);
                for (int ci = si; ci <= ei; ci++) {
                    int v = ci == hi ? 0 : cost[i - 1][ci - 1];
                    for (int cj = sj; cj <= ej; cj++) {
                        dp[k][i][ci] = min(dp[k][i][ci], dp[k - (ci != cj)][i - 1][cj] + v);
                    }
                }
            }
        }
        const int ans = *min_element(begin(dp[target][m]), end(dp[target][m]));
        return ans >= INF ? -1 : ans;
    }
};

int main() {
    vector<int> houses = {0, 2, 1, 2, 0};
    vector<vector<int>> cost = {{1,  10},
                                {10, 1},
                                {10, 1},
                                {1,  10},
                                {5,  1}};
    int m = 5, n = 2, target = 3;
    Solution Instance;
    int ans = Instance.minCost(houses, cost, m, n, target);
    cout << ans << endl;
    return 0;
}
