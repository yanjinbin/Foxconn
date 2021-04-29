#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include <stack>

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

//参考花花酱解法 https://youtu.be/q2Wh5v___r8
// time: O(M*N*K)*O(M+N)
// tag:  dp
// base condition k=0, dp(m,n,0)=hasApple(m,m,M-1,N-1);
// 切割点 Mi和Ni
// dp(m,n,k) = sum(dp(Mi+1,n,k-1)*hasApple(m,n,Mi,N-1))+sum(dp(m,Ni+1,k-1)*hasApple(m,n,M-1,Ni));
class Solution {
public:
    int ways(vector<string> &pizza, int K) {
        int M = pizza.size(), N = pizza[0].size();
        vector <vector<int>> preSum(M + 1, vector<int>(N + 1));// padding;
        for (int y = 0; y < M; y++) {
            for (int x = 0; x < N; x++) {
                preSum[y + 1][x + 1] =
                        preSum[y + 1][x] + preSum[y][x + 1] - preSum[y][x] + (pizza[y][x] == 'A');
            }
        }
        auto hasApple = [&](int y1, int x1, int y0, int x0) {
            return (preSum[y1 + 1][x1 + 1] - preSum[y1 + 1][x0] - preSum[y0][x1 + 1] + preSum[y0][x0]) > 0;
        };
        vector < vector < vector < int>>> cache(M, vector < vector < int >> (N, vector<int>(K, -1)));
        function<int(int, int, int)> dp = [&](int m, int n, int k) -> int {
            // base condition
            if (k == 0) return hasApple(M - 1, N - 1, m, n);

            int &ans = cache[m][n][k];
            if (ans != -1) return ans;
            ans = 0;
            // 取M-1 N-1 防止BASE CONDITION 要去判断越界问题
            for (int y = m; y < M - 1; y++) {// cut horizontal
                ans = (ans + hasApple(y, N - 1, m, n) * dp(y + 1, n, k - 1)) % kMod;
            }
            for (int x = n; x < N - 1; x++) {// vertical cur
                ans = (ans + hasApple(M - 1, x, m, n) * dp(m, x + 1, k - 1)) % kMod;
            }
            return ans;
        };
        return dp(0, 0, K - 1);
    }
};