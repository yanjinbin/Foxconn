
#include <algorithm>
#include <cmath>
#include <cstdlib>
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
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define debug puts("⚡️⚡️");
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define pii pair<int, int>
#define LL long long
#define LD long double
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second

// tag: dp
//  L 左边都是0 R 右边都是1
class Solution {
public:
  int minFlipsMonoIncr(string s) {
    const int n = s.size();
    vector<int> L(n + 1, 0);
    vector<int> R(n + 1, 0);
    L[0] = s[0] - '0';
    R[n - 1] = '1' - s[n - 1];
    for (int i = 1; i < n; i++) {
      L[i] = L[i - 1] + s[i] - '0';
    }
    for (int i = n - 2; i >= 0; i--) {
      R[i] = R[i + 1] + '1' - s[i]
    }
    int ans = R[0];
    for (int i = 1; i <= n; i++) {
      ans = min(ans, L[i - 1] + R[i]);
    }
    return ans;
  }
};