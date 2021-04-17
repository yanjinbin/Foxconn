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
const int MAX_VALUE = 0x7FFFFFFF;
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

// tag: dp  dp[i][cur]=min(dp[i][cur],dp[i-1][prev]+min(m-abs(cur-prev),abs(cur-prev)))
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        unordered_map<char, vector<int>> letters2pos;
        for (int i = 0; i < ring.size(); i++) letters2pos[ring[i]].push_back(i);
        int n = key.size();
        int m = ring.size();
        auto dp = vector < vector < int >> (n, vector<int>(m, INF));
        // init
        for (int pos:letters2pos[key[0]]) dp[0][pos] = min(dp[0][pos], min(pos, m - pos));
        for (int i = 1; i < n; i++) {
            for (int cur:letters2pos[key[i]]) {
                for (int prev:letters2pos[key[i - 1]]) {
                    dp[i][cur] = min(dp[i][cur],
                                     dp[i - 1][prev] + min(abs(cur - prev), m - abs(cur - prev)));// M- 是因为旋转方向
                }
            }
        }
        int ans = MAX_VALUE;
        for (int pos:letters2pos[key[n - 1]]) {
            ans = min(ans, dp[n - 1][pos]);
        }
        return ans + n;
    }
};

int main() {
    Solution INSTANCE;
    string ring = "godding", key = "gd";
    int ans = INSTANCE.findRotateSteps(ring, key);
    cout << ans << endl;
    return 0;
}