#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <stack>
#include <cmath>

using namespace std;

const int INF = 0x3F3F3F3F, MAX_VALUE = 0x7FFFFFFF, MIN_VALUE = 0x80000000, MOD = 1E9 + 7;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define debug puts("pigtoria bling bling ⚡️⚡️");
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define LL long long
#define LD long double
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second

// 多重背包
class Solution {
public:
    int MultiPack(int n, int v, vector<vector<int>> data) {
        vector<int> dp(v + 1);
        for (int i = 0; i < data.size(); i++) {
            int vi = data[i][0], wi = data[i][1], si = data[i][2];
            MultiplePack(vi, wi, si, dp, v);
        }
        return dp[v];
    }

    int MultiplePack(int vi, int wi, int si, vector<int> &dp, int V) {
        if (vi * si >= V) {
            CompletePack(vi, wi, dp, V);
            return dp[V];
        }
        int s = 1;
        while (s < si) {//条件：amount-s>0
            ZeroOnePack(s * vi, s * wi, dp, V);
            si -= s;
            s *= 2;
        }
        ZeroOnePack(si * vi, si * wi, dp, V);
        return dp[V];
    }

    // 抽象化: 抽取01背包问题为处理一件物品
    int ZeroOnePack(int vi, int wi, vector<int> &dp, int V) {
        for (int j = V; j >= vi; j--) {
            dp[j] = max(dp[j], dp[j - vi] + wi);
        }
        return dp[V];// 返回的是容量为V时候,处理一件物品获取的最大值
    }

    // 抽象化: 对一种物品的处理过程
    int CompletePack(int vi, int wi, vector<int> &dp, int V) {
        for (int j = 0; j <= V; j++) {
            if (j >= vi) dp[j] = max(dp[j], dp[j - vi] + wi);
        }
        return dp[V];
    }
};

int main() {
    int n, v;
    cin >> n >> v;
    vector <vector<int>> data;
    int vi, wi, si;
    for (int i = 0; i < n; ++i) {
        cin >> vi >> wi >> si;
        data.EB(vector < int > {vi, wi, si});
    }
    Solution INSTANCE;
    int ans = INSTANCE.MultiPack(n, v, data);
    cout << ans << endl;
    return 0;
}