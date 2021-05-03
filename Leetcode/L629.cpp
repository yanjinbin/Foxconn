#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include <stack>
#include <numeric>
#include <set>
#include <unordered_set>

using namespace std;
const int MAX_VALUE = 0x7FFFFFFF, MIN_VALUE = 0x80000000, INF = 0x3F3F3F3F, kMod = 1E9 + 7;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define debug puts("⚡️⚡️ bling bling ⚡️⚡️");
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
public:// k逆序对 dp(i,j)=sum(dp(i-1,j-k),k --> 0,1,2..i-2,i-1;  O(N3)
    // 优化下==>j编程j-1代入,得出dp(i,j)=dp(i,j-1)+dp(i-1,j)-dp(i-1,j-i); O(N2)
    int kInversePairs(int n, int k) {
        vector <vector<long>> dp(n + 1, vector<long>(k + 1, 0));
        //init
        for (int i = 0; i < n + 1; ++i) {
            dp[i][0] = 1;
        }
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < k + 1; ++j) {
                if (j >= i) {
                    dp[i][j] = dp[i - 1][j] - dp[i - 1][j - i] + dp[i][j - 1] + kMod;// dp[i-1][j-I]可能过大
                } else {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                }
                dp[i][j] %= kMod;
            }
        }
        return dp[n][k];
    }
};