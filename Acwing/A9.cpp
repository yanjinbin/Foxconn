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

class Solution {
public:
    int GroupPacK(int N, int V, vector<vector<pii>> &groups) {
        vector<int> dp(V + 1);
        for (int i = 0; i < N; i++) {
            for (int v = V; v >= 0; v--) {
                for (int j = 0; j < groups[i].size(); j++) {
                    if (v >= groups[i][j].first)dp[v] = max(dp[v], dp[v - groups[i][j].first] + groups[i][j].second);
                }
            }
        }
        return dp[V];
    }
};


// 分组背包
int main() {
    int N, V;
    cin >> N >> V;
    int si, vij, wij;
    vector <vector<pii>> groups;
    for (int i = 0; i < N; i++) {
        cin >> si;
        vector <pii> group;
        for (int i = 0; i < si; ++i) {
            cin >> vij >> wij;
            group.EB(make_pair(vij, wij));
        }
        groups.EB(group);
        group.clear();
    }
    Solution INSTANCE;
    int ans = INSTANCE.GroupPacK(N, V, groups);
    cout << ans << endl;
    return 0;
}