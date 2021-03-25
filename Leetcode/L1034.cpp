#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;
const int INF = 0x3F3F3F3F;
#define debug puts("pigtoria bling bling ⚡️⚡️");
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ll long long
#define pii pair<int, int>

class Solution {
public:
    vector<int> dirs = {-1, 0, 1, 0, -1};
    vector <vector<int>> seen;
    vector <vector<int>> res;
    vector <vector<int>> colorBorder(vector <vector<int>> &grid, int r0, int c0,
                                     int color) {
        int origin = grid[r0][c0];
        if (color == origin) return grid;
        res = grid;// 当时理解错误,其实需要一个copy的
        seen.resize(grid.size(), vector<int>(grid[0].size()));
        seen[r0][c0] = true;
        dfs(grid, r0, c0, color, origin);
        return res;

    }

    void dfs(vector <vector<int>> &grid, int r, int c, int color, int origin) {
        if (r == 0 || c == 0 || r == grid.size() - 1 || c == grid[0].size() - 1) {
            // 达到边界了 不得不染色
            res[r][c] = color;//染色
        }
        for (int i = 0; i < 4; i++) {
            int nr = r + dirs[i], nc = c + dirs[i + 1];
            if (nr < 0 || nc < 0 || nr >= grid.size() || nc >= grid[0].size()) continue;
            if (grid[nr][nc] != origin) {
                // 染色
                res[r][c] = color;
                continue;
            }
            if (seen[nr][nc]) continue;
            seen[nr][nc] = true;
            dfs(grid, nr, nc, color, origin);
        }
    }
    /* vector <vector<int>> colorBorder(vector <vector<int>> &grid, int r0, int c0,
                                      int color) {
         int origin = grid[r0][c0];
         if (origin == color) return grid;
         int m = grid.size(), n = grid[0].size();
         seen.resize(m, vector<bool>(n, false));

         seen[r0][c0] = true;
         if (r0 - 1 >= 0) dfs(grid, r0 - 1, c0, r0, c0, color);
         if (c0 - 1 >= 0) dfs(grid, r0, c0 - 1, r0, c0, color);
         if (r0 + 1 < grid.size())dfs(grid, r0 + 1, c0, r0, c0, color);
         if (c0 + 1 < grid[0].size())dfs(grid, r0, c0 + 1, r0, c0, color);

         return grid;
     }*/

    /*  void dfs(vector <vector<int>> &grid, int nr, int nc, int r, int c, int color) {
          if (nr < 0 || nc < 0 || nr >= grid.size() || nc >= grid[0].size()) {
              grid[r][c] = color;
              return;
          }
          if (seen[nr][nc]) return;
          else seen[nr][nc] = true;

          if (grid[r][c] != grid[nr][nc]) {
              grid[r][c] = color; // 边界染色
              cout << "染色了啊" << endl;
              return;
          }
          for (int i = 0; i < 4; i++) {
              dfs(grid, nr + dirs[i], nc + dirs[i + 1], nr, nc, color);
          }
      }*/
};

int main() {
    Solution INSTANCE;
    vector <vector<int>> grid = {{1, 1, 1, 1, 1},
                                 {1, 1, 1, 1, 1},
                                 {1, 1, 1, 1, 1},
                                 {1, 1, 1, 1, 1},
                                 {1, 1, 1, 1, 1}};
    int r0 = 2, c0 = 2, color = 3;
    vector <vector<int>> ans = INSTANCE.colorBorder(grid, r0, c0, color);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j] << " | ";
        }
        cout << endl;
    }
    return 0;
}
