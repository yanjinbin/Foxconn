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

// tag: topology sort
class Solution {
public:
  int minimumTime(int n, vector<vector<int>> &edges, vector<int> &time) {
    vector<vector<int>> G(n + 1);
    vector<int> indeg(n + 1, 0);
    for (auto edge : edges) {
      int s = edge[0], e = edge[1];
      G[s].push_back(e);
      indeg[e]++;
    }

    queue<int> q;
    vector<int> t(n + 1);
    for (int i = 1; i <= n; i++) {
      if (indeg[i] == 0) {
        q.push(i);
        t[i] = time[i - 1];
      }
    }
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (auto nxt : G[cur]) {
        t[nxt] = max(t[nxt], t[cur] + time[nxt - 1]);
        indeg[nxt]--;
        if (indeg[nxt] == 0) {
          q.push(nxt);
        }
      }
    }
    // 从 1开始 1-index arr
    auto ans = *max_element(t.begin() + 1, t.end());
    return ans;
  }
};