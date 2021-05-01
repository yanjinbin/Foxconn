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
#define pii pair<int, int>
#define LL long long
#define LD long double
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second

// tag: 线性dp
int main() {
    fastio
    int n;
    cin >> n;
    vector <vector<int>> w(n + 1, vector<int>(n + 1));
    vector <vector<int>> f(n + 1, vector<int>(n + 1));
    FOR(i, 1, n + 1) {
        FOR(j, 1, i + 1) {
            cin >> w[i][j];
        }
    }
    // INIT
    for (int i = 1; i <= n; i++) {
        f[n][i] = w[n][i];
    }
    // 从底到最上层
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            f[i][j] = max(f[i + 1][j], f[i + 1][j + 1]) + w[i][j];
        }
    }
    cout << f[1][1] << endl;
    return 0;
}