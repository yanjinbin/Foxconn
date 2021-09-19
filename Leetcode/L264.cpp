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

// 丑数Ⅱ
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> q({1});
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < n - 1; ++i) {
            int num = min(min(q[a] * 2, q[b] * 3), q[c] * 5);
            if (q[a] * 2 == num) a++;
            if (q[b] * 3 == num) b++;
            if (q[c] * 5 == num) c++;
            q.EB(num);
        }
        return q[n - 1];
    }
};