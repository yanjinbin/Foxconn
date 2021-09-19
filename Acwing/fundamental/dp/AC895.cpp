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

// tag: 线性dp
int main() {
    fastio
    int N;
    cin >> N;
    vector<int> arr;
    int val;
    for (int i = 0; i < N; i++) {
        cin >> val;
        arr.EB(val);
    }
    vector<int> dp(N, 1);

    int ans = MIN_VALUE;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}