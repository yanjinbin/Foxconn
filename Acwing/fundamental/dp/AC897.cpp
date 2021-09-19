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

// dp(i,j) = dp(i-1,j-1) // s[i]==t[j]
// dp(i,j) = max(dp(i-1,j),dp(i,j-1))
int main() {
    fastio
    int N, M;
    cin >> N >> M;
    string s, t;
    cin >> s >> t;
    cout << N << M << s << t;
    vector <vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (s[i] != t[j]) dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            else dp[i + 1][j + 1] = dp[i][j] + 1;
        }
    }
    cout << dp[N][M] << endl;
    return 0;
}