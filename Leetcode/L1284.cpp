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

// tag: BFS  https://youtu.be/oxTtbZ6t-F0?t=662
class Solution {
public:
  int minFlips(vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();
    vector<int> dirs = {0, -1, 0, 1, 0, 0};
    auto flip = [&](int s, int x, int y) {
      for (int i = 0; i < 5; i++) {
        int nx = dirs[i] + x;
        int ny = dirs[i + 1] + y;
        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
          continue;
        s = s ^ (1 << (ny * n + nx));
      }
      return s;
    };

    int step = 0;
    vector<int> seen(1 << (m * n));
    queue<int> q;
    int start = 0;
    for (int y = 0; y < m; y++) {
      for (int x = 0; x < n; x++) {
        start |= (mat[y][x] << (y * n + x));
      }
    }

    if (start == 0)
      return 0; //写成start=0 常犯错误了!!
    seen[start] = 1;
    q.push(start);

    while (!q.empty()) {
      int len = q.size();
      for (int i = 0; i < len; i++) {
        int s = q.front();
        if (s == 0)
          return step;
        q.pop();
        for (int y = 0; y < m; y++) {
          for (int x = 0; x < n; x++) {
            int t = flip(s, x, y);
            if (seen[t])
              continue;
            seen[t] = 1;
            q.push(t);
          }
        }
      }
      step++;
    }
    return -1;
  }
};
