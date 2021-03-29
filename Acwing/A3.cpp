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
    int CompletePack(int n, int v, vector<pii > data) {
        vector<int> dp(v + 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= v; j++) {
                if(j>=data[i].first){
                    dp[j]=max(dp[j],dp[j-data[i].first]+data[i].second);
                }
            }
        }
        return dp[v];
    }
};

int main() {
    int n, v;
    cin >> n >> v;
    vector <pii> data;
    for (int i = 0; i < n; i++) {
        int vi, wi;
        cin >> vi >> wi;
        data.EB(make_pair(vi, wi));
    }
    Solution INSTANCE;
    int ans = INSTANCE.CompletePack(n, v, data);
    cout << ans << endl;
    return 0;
}