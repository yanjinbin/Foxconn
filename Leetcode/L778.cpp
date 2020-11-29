#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int r, c, h;

    bool operator<(const Node &other) const {
        return this->h > other.h;
    }
};

int swimInWater(vector<vector<int>> &grid) {
    const int n = grid.size();
    priority_queue<Node> q;
    q.push({0, 0, grid[0][0]});
    vector<int> seen(n * n);
    vector<int> dirs{-1, 0, 1, 0, -1};
    seen[0 * n + 0] = 1;
    while (!q.empty()) {
        auto node = q.top();
        q.pop();
        int t = node.h;
        int row = node.r;
        int col = node.c;
        if (row == n - 1 && col == n - 1) return t;
        for (int i = 0; i < 4; i++) {
            int nr = row + dirs[i];
            int nc = col + dirs[i + 1];
            int idx = nr * n + nc;
            if (nr < 0 || nc < 0 || nr >= n || nc >= n || seen[idx] == 1) continue;
            seen[idx] = 1;
            q.push({nr, nc, max(t, grid[nr][nc])});
        }
    }
    return -1;
}


int main() {
    vector<vector<int>> grid = {{0,  1,  2,  3,  4},
                                {24, 23, 22, 21, 5},
                                {12, 13, 14, 15, 16},
                                {11, 17, 18, 19, 20},
                                {10, 9,  8,  7,  6}};
    cout << swimInWater(grid) << endl;
    return 0;
}