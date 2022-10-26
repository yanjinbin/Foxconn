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

class Solution {
public:
  int shortestBridge(vector<vector<int>> &G) {
    // 先找出 1st 连通分量, 全部置为2。
    queue<pii> q;
    bool found = false; // first found, then stop.
    int m = G.size(), n = G[0].size();
    for (int i = 0; i < m && !found; i++) {   // i->y
      for (int j = 0; j < n && !found; j++) { // j->x
        if (G[i][j]) {
          dfs(G, j, i, q);
          found = true;
        }
      }
    }

    // BFS
    int step = 0;
    vector<int> dirs{0, 1, 0, -1, 0};
    while (!q.empty()) {
      int len = q.size();
      while (len--) {
        int x = q.front().FI, y = q.front().SE;
        q.pop();
        for (int i = 0; i < 4; i++) {
          int nx = x + dirs[i];
          int ny = y + dirs[i + 1];
          if (nx < 0 || ny < 0 || nx >= n || ny >= m || G[ny][nx] == 2)
            continue;
          if (G[ny][nx] == 1)
            return step;
          // 把非2的都变成2
          G[ny][nx] = 2;
          q.emplace(nx, ny);
        }
      }
      step++;
    }
    return -1;
  }

  void dfs(vector<vector<int>> &G, int x, int y, queue<pii> &q) {
    if (x < 0 || y < 0 || x >= G[0].size() || y >= G.size() || G[y][x] != 1) {
      return;
    }
    G[y][x] = 2;
    q.emplace(x, y); // insert last
    dfs(G, x - 1, y, q);
    dfs(G, x, y - 1, q);
    dfs(G, x + 1, y, q);
    dfs(G, x, y + 1, q);
  }
};