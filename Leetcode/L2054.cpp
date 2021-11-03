#include <algorithm>
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
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
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
// tag: rollingMax binary-search
class Solution {

public:
  int maxTwoEvents(vector<vector<int>> &events) {
    int n = events.size();
    auto cmp = [](vector<int> &a, vector<int> &b) -> bool { return a[1] < b[1]; };
    sort(events.begin(), events.end(), cmp);
    vector<int> rollingMax(n);
    int m = 0;
    for (int i = 0; i < n; i++) {
      m = max(m, events[i][2]);
      rollingMax[i] = m;
    }
    vector<int> endTimes;
    int ret = 0;
    for (int i = 0; i < n; i++) {
      int a = events[i][0] - 1, b = events[i][1], v = events[i][2];
      ret = max(ret, v);
      auto iter = upper_bound(endTimes.begin(), endTimes.end(), a);
      if (iter != endTimes.begin()) {
        int idx = prev(iter) - endTimes.begin();
        ret = max(ret, rollingMax[idx] + v);
      }
      endTimes.push_back(b);
    }
    return ret;
  }
};