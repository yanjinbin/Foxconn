#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <cmath>
#include <climits>

using namespace std;
const int MAX_VALUE = 0x7FFFFFFF, MIN_VALUE = 0x80000000, INF = 0x3F3F3F3F, kMod = 1E9 + 7;
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

// tag: math
// 我们发现对于 n > 1 的数字乘积中，回文数字应该是 2 n 位的。
// 于是我们通过一个 n 位数字将其翻转之后拼接起来便可以构成所有 2 n 位的回文数字。
// 之后再从大到小判断这些数字是否可以分解为两个 n 位数的乘积即可。
class Solution {
public:
    int largestPalindrome(int n) {
        if (n==1) return 9;
        LL lo = pow(10, n - 1);
        LL hi = pow(10, n) - 1;
        for (LL i = hi; i >= lo; i--) {

            string s = to_string(i);
            reverse(s.begin(),s.end());
            LL x = stoll(to_string(i)+s);

            for (LL d = hi; d >= sqrt(x); d--) {
                if (x % d == 0 && (x / d) >= lo) {
                    return x%1337;
                }
            }
        }
        return -1;
    }

};