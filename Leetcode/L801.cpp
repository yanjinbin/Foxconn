#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

const int MAX_VALUE = 0x7FFFFFFF, MIN_VALUE = 0x80000000, INF = 0x3F3F3F3F, kMod = 1E9 + 7;
#define ready ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
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

class Solution {
public:
  // dfs https://www.bilibili.com/video/BV1FW411o7tL/
  int minSwap_(vector<int> &nums1, vector<int> &nums2) {
    int ans = INT_MAX;
    dfs(nums1, nums2, 1, 0, ans);
    return ans;
  }

  dfs(vector<int> &a, vector<int> &b, int i, int c, int &ans) {
    if (c >= ans) {
      return;
    }
    if (i == a.size()) {
      ans = min(ans, c);
      return;
    }
    if (a[i] > a[i - 1] && b[i] > b[i - 1]) {
      dfs(a, b, i + 1, c, ans);
    }
    if (a[i] > b[i - 1] &&
        b[i] > a[i - 1]) { // 可以交换也可以不交换 // 因此dfs后 需要复原再去尝试 主要是后续能有机会严格递增
      swap(a[i], b[i]);
      dfs(a, b, i + 1, c + 1, ans);
      swap(a[i], b[i])
    }
  }

  // dp
  int minSwap(vector<int> &a, vector<int> &b) {
    const int n = a.size();
    vector<int> swap(n, INF), keep(n, INF);
    swap[0] = 1, keep[0] = 0;

    for (int i = 1; i < n; i++) {
      if (a[i] > a[i - 1] && b[i] > b[i - 1]) {
        keep[i] = keep[i - 1];
        swap[i] = swap[i - 1] + 1;
      }
      if (b[i] > a[i - 1] && a[i] > b[i - 1]) {
        swap[i] = min(swap[i], keep[i - 1] + 1);
        keep[i] = min(keep[i], swap[i - 1]);
      }
    }
    return min(keep[n - 1], swap[n - 1]);
  }
}