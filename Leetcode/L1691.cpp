#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxHeight(vector<vector<int>> &w) {
        for (auto &x : w) sort(x.begin(), x.end());
        sort(w.begin(), w.end(),
             greater<vector<
                 int>>());  //  https://www.bilibili.com/video/BV1ht4y1Y7yD
                            //  变成单调下降子序列问题
        const int n = w.size();
        vector<int> dp(n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            dp[i] = w[i][2];
            for (int j = 0; j < i; j++) {
                if (w[j][0] >= w[i][0] && w[j][1] >= w[i][1] &&
                    w[j][2] >= w[i][2]) {
                    dp[i] = max(dp[i], dp[j] + w[i][2]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
// https://leetcode-cn.com/contest/weekly-contest-219/problems/maximum-height-by-stacking-cuboids/
int main() {
    Solution INSTANCE;
    vector<vector<int>> cuboid = {{50, 45, 20}, {95, 37, 53}, {45, 23, 12}};
    cout << INSTANCE.maxHeight(cuboid);
    return 0;
}