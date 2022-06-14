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

class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>> &g) {
    int n = g.size(), m = g[0].size(), cnt = n * m;
    vector<int> ans(cnt);
    int x = 0, y = 0, dir = 1, idx = 0;
    while (idx != cnt) {
      ans[idx++] = g[x][y];
      int nx = x, ny = y;
      if (dir == 1) {
        nx = x - 1, ny = y + 1;
      } else {
        nx = x + 1, ny = y - 1;
      }

      if (idx < cnt && (nx < 0 || nx >= n || ny < 0 || ny >= m)) {
        if (dir == 1) {
          nx = y + 1 < m ? x : x + 1;
          ny = y + 1 < m ? y + 1 : y;
        } else {
          nx = x + 1 < n ? x + 1 : x;
          ny = x + 1 < n ? y : y + 1;
        }
        dir = dir * -1;
      }
      x = nx;
      y = ny;
    }
    return ans;
  }
};
