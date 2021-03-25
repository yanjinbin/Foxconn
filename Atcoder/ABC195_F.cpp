#include <vector>
#include <iostream>

using namespace std;
#define LL long long
#define LD long double
#define ioinit ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second


signed main() {
    ioinit

    vector<LL> primes;
    for (int i = 2; i < 72; i++) {
        bool flag = true;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) flag = false;
        }
        if (flag) primes.emplace_back(i);
    }

    LL A, B;
    cin >> A >> B;
    vector<LL> v(B - A + 1);
    for (LL i = A; i <= B; i++) {
        LL mask = 0;
        for (int j = 0; j < primes.size(); j++) {
            if (i % primes[j] == 0) {
                mask |= (1 << j);
            }
        }
        v[i - A] = mask;
    }

    vector<LL> dp(1 << primes.size());
    dp[0] = 1;
    for (LL x: v) {
        for (LL mask = 0; mask < (1 << primes.size()); mask++) {
            if (dp[mask] && (mask & x) == 0) {
                dp[mask | x] += dp[mask];
            }
        }
    }

    LL ans = 0;
    for (LL i = 0; i < (1 << primes.size()); i++) ans += dp[i];
    cout << ans;
}