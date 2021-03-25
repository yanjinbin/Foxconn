#include <iostream>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 0x3F3F3F3F;
#define debug puts("bling bling ⚡️⚡️");
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ll long long
#define pii pair<int, int>
int maxN = 1001;

int main() {
    int N, V;
    cin >> N >> V;
    vector<int> c(N+1);
    vector<int> w(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> c[i] >> w[i];
    }
    vector <vector<int>> dp(N + 1, vector<int>(V + 1));
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= V; j++) {
            if (j >= c[i]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c[i]] + w[i]);
            else dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[N][V];
    return dp[N][V];
}


