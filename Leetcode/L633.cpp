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

const int MAX_VALUE = 0x7FFFFFFF, MIN_VALUE = 0x80000000, INF = 0x3F3F3F3F, MOD = 1E9 + 7;
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
    bool judgeSquareSum(int c) {
        long lo = 0, hi = (long) sqrt(c);
        while (lo <= hi) {
            long sum = lo * lo + hi * hi;
            if (sum < c) {
                lo++;
            } else if (sum > c) {
                hi--;
            } else {
                return true;
            }
        }
        return false;

    }

    int sqrt(int c) {
        int lo = 1, hi = c + 1;
        while (lo < hi) {
            int mid = (hi - lo) / 2 + lo;
            if (mid < c / mid) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};