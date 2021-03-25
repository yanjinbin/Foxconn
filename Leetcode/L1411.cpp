#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int numOfWays_01(int n) {
        int MOD = 1e9 + 7;
        // dp(i,type) // 表示第i行填色方法位type时候的方案数目 ∑dp(i-1,type')
        vector<int> types;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (i != j && j != k) {
                        types.push_back(i * 9 + j * 3 + k * 1);// 配色表示
                    }
                }
            }
        }
        int cnt = types.size();
        // 处理可以相连的配色
        vector<vector<int>> adj(cnt, vector<int>(cnt));
        for (int i = 0; i < cnt; i++) {
            int x1 = types[i] / 9, y1 = types[i] / 3 % 3, z1 = types[i] % 3;
            for (int j = 0; j < cnt; j++) {
                if (i != j) {
                    int x2 = types[j] / 9, y2 = types[j] / 3 % 3, z2 = types[j] % 3;
                    if (x1 != x2 && y1 != y2 && z1 != z2) {
                        adj[i][j] = 1;
                    }
                }
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(cnt));
        // init 第一行1;
        for (int i = 0; i < cnt; i++) {
            dp[1][i] = 1;
        }
        for (int i = 2; i <= n; i++) {// 第2行
            for (int j = 0; j < cnt; j++) {// 配色方案种类
                for (int k = 0; k < cnt; k++) {
                    if (adj[j][k]) {
                        dp[i][j] += dp[i - 1][k];
                        dp[i][j] = dp[i][j] % MOD;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < cnt; i++) {
            ans += dp[n][i];
            ans = ans % MOD;
        }
        return ans;
    }

    int numOfWays_02(int n) {
        int MOD = 1e9 + 7;
        // 归类为ABC ABA 各6种
        int abc = 6, aba = 6;
        for (int i = 2; i <= n; i++) {
            int _abc = (2LL * abc + 2LL * aba) % MOD;
            int _aba = (2LL * abc + 3LL * aba) % MOD;
            abc = _abc;
            aba = _aba;
        }
        return (abc + aba) % MOD;
    }
};

int main() {
    Solution INSTANCE;
    cout << INSTANCE.numOfWays_01(2) << "\t" << INSTANCE.numOfWays_02(2);
    return 0;
}