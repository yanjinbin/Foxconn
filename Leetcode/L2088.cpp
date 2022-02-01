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
#define debug puts("⚡️⚡️");
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define LL long long
#define LD long double
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second

//go version https://go.dev/play/p/7qq9TFZMyLG
class Solution {
public:
  int countPyramids(vector<vector<int>> &grid) {

    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> left(m, vector<int>(n));
    vector<vector<int>> right(m, vector<int>(n));
    // 不能合并 拆不开
    // dp 表示 i,j位基地底座能取得最大长度半径得金字塔个数,可以正立也可以倒立
    vector<vector<int>> dpUp(m, vector<int>(n));
    vector<vector<int>> dpDown(m, vector<int>(n));
    // left
    FOR(i, 0, m) {
      int cnt = 0;
      FOR(j, 0, n) {
        if (grid[i][j] == 0)
          cnt = 0;
        else
          cnt++;
        left[i][j] = cnt;
      }
    }
    // right
    FOR(i, 0, m) {
      int cnt = 0;
      FORD(j, n - 1, 0) {
        if (grid[i][j] == 0)
          cnt = 0;
        else
          cnt++;
        right[i][j] = cnt;
      }
    }

    int ans = 0;
    FOR(i, 0, m) {
      FOR(j, 0, n) {
        if (grid[i][j] == 0) continue;
        // CORNER CASE
        if (i == 0) {
          dpUp[i][j] = 1;
        } else {
          dpUp[i][j] = min(min(left[i][j], right[i][j]), dpUp[i - 1][j] + 1);
        }
        ans += dpUp[i][j] - 1;
      }
    }

    FORD(i, m - 1, 0) {
      FOR(j, 0, n) {
        if (grid[i][j] == 0) continue;
        // CORNER CASE
        if (i == m - 1) {
          dpDown[i][j] = 1;
        } else {
          dpDown[i][j] = min(min(left[i][j], right[i][j]), dpDown[i + 1][j] + 1);
        }
        ans += dpDown[i][j] - 1;
      }
    }
    return ans;
  }
};
