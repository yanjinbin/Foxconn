#include <algorithm>
#include <assert.h>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int MAX_VALUE = 0x7FFFFFFF, MIN_VALUE = 0x80000000, INF = 0x3F3F3F3F, kMod = 1E9 + 7;
#define ready ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define debug puts("⚡️⚡️bling bling ⚡️⚡️");
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define pii pair<int, int>
#define LL long long
#define LD long double
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second

// https://bit.ly/3Ey9taZ TAG: 容斥原理 二分查找
class Solution {
public:
  int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

  int lcm(int a, int b) { return a * b / gcd(a, b); }

  int nthMagicalNumber(int n, int a, int b) {
    int c = lcm(a, b);
    long l = 0, r = (long)1E18;
    while (l < r) {
      long mid = l + (r - l) / 2;
      if (check(mid, a, b, c) >= n) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return (int)(l % kMod);
  }
  long check(long x, long a, long b, long c) { return (x / a + x / b - x / c); }
};

int main() {
  Solution INSTANCE;
  assert(INSTANCE.nthMagicalNumber(5, 4, 7) == 13);
  return 0;
}
