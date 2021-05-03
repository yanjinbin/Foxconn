#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include <stack>

using namespace std;

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
    int preimageSizeFZF(int K) {
        long lo = 1, hi = 5e9 + 1;
        while (lo < hi) {
            long mid = (hi - lo) / 2 + lo;
            if (countTrailZero(mid) < K) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        if (lo > hi) return 0; // lo=hi 理论上符合现实
        // 只有5 和 0  两种return value.
        if (countTrailZero(lo) == K) {
            return 5;
        } else {
            return 0;
        }
    }

    long countTrailZero(long x) {
        long base = 5;
        long ans = 0;
        while (x / base > 0) {
            ans += x / base;
            base = base * 5;
        }
        return ans;
    }
};