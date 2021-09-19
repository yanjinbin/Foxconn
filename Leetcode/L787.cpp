#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <cmath>
#include <climits>

using namespace std;
const int MAX_VALUE = 0x7FFFFFFF, MIN_VALUE = 0x80000000, INF = 0x3F3F3F3F, kMod = 1E9 + 7;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
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

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K) {
        vector < vector < vector < int>>>G(n);
        int u, v, w;
        for (vector<int> flight: flights) {
            u = flight[0], v = flight[1], w = flight[2];
            G[u].PB({v, w});
        }
        vector <vector<int>> seen(n, vector<int>(K + 2, INF));
        seen[src][0] = 0;
        multiset <vector<int>> q;
        q.insert({0, 0, src});
        while (!q.empty()) {
            vector<int> flight = *q.begin();
            int cost = flight[0], step = flight[1], cur = flight[2];
            q.erase(q.begin());
            if (cur == dst) return cost;
            if (step > K) continue;
            for (vector<int> flight:G[cur]) {
                int v = flight[0], w = flight[1];
                if (cost + w < seen[v][step + 1]) {
                    seen[v][step + 1] = cost + w;
                    q.insert({cost + w, step + 1, v});
                }
            }
        }
        return -1;
    }

    // dp 最多做K+1次飞机
    int findCheapestPrice_(int n, vector<vector<int>> &flights, int src, int dst, int K) {
        vector <vector<int>> dp(K + 2, vector<int>(n, INF));
        dp[0][src] = 0;
        for (int k = 1; k <= K + 1; ++k) {
            dp[k][src] = 0;
            for (auto flight:flights) {
                int u = flight[0], v = flight[1], w = flight[2];
                dp[k][v] = min(dp[k][v], dp[k - 1][u] + w);
            }
        }
        int ret = dp[K + 1][dst];
        return ret >= INF ? -1 : ret;
    }
    // dp 最多k次
    int findCheapestPrice__(int n, vector<vector<int>> &flights, int src, int dst, int K) {
        vector <vector<int>> dp(K + 2, vector<int>(n, INF));
        dp[0][src] = 0;
        for (int k = 1; k <= K + 1; ++k) {
            for (auto flight:flights) {
                int u = flight[0], v = flight[1], w = flight[2];
                dp[k][v] = min(dp[k][v], dp[k - 1][v]);
                dp[k][v] = min(dp[k][v], dp[k - 1][u] + w);
            }
        }
        int ret = dp[K + 1][dst];
        return ret >= INF ? -1 : ret;
    }
};