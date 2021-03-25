
#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include <stack>

using namespace std;

const int INF = 0x3F3F3F3F;
const int MOD = 1E9 + 7;
#define ready ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
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

// 石子游戏IV
class Solution {
public:
    vector<int> dp;

    bool winnerSquareGame(int n) {
        dp.resize(n + 1, -1);
        dp[0] = 0;// 0 lose 1 win -1 unknown
        return dfs(n);
    }
    // top-down
    bool dfs(int n) {
        if (dp[n] != -1) {
            return dp[n];
        }
        for (int i = 1; i * i <= n; i++) {
            if (dfs(n - i * i) == 0) { // 如果对方会输,则你有赢得机会
                dp[n] = 1;
                return true;
            }
        }
        dp[n] = 0;
        return false;
    }
    // bottom-up
    bool winnerSquareGame_(int n) {
        vector<bool> dp(n + 1, false);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; ++j) {
                if (!dp[i - j * j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }

};

int main() {
    return 0;
}