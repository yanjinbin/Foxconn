#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

#define pii pair<int, int>
#define FOR(i, a, b) for (int i = a; i < b; i++)
using namespace std;

class DSU {
public:
  DSU(int n) {
    ranks_ = vector<int>(n + 1, 0);
    parents_ = vector<int>(n + 1, 0);

    for (int i = 0; i < parents_.size(); ++i)
      parents_[i] = i;
  }
  bool Union(int u, int v) {
    int pu = Find(u);
    int pv = Find(v);
    if (pu == pv)
      return false;
    if (ranks_[pv] < ranks_[pu])
      parents_[pv] = pu;
    else if (ranks_[pu] < ranks_[pv])
      parents_[pu] = pv;
    else {
      parents_[pv] = pu;
      ranks_[pu] += 1;
    }
    return true;
  }
  int Find(int u) {
    if (u != parents_[u])
      parents_[u] = Find(parents_[u]);
    return parents_[u];
  }

private:
  vector<int> parents_;
  vector<int> ranks_;
};

class Solution {

public:
  vector<vector<int>> matrixRankTransform(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    DSU dsu(n * m + 1);
    vector<vector<int>> next(m * n);
    vector<int> indeg(m * n, 0);

    FOR(i, 0, m) {
      vector<pii> temp;
      FOR(j, 0, n) temp.push_back({matrix[i][j], i * n + j});
      sort(temp.begin(), temp.end());
      FOR(j, 1, n) {
        pii u = temp[j - 1], v = temp[j];
        if (u.first < v.first) {
          next[u.second].push_back(v.second);
          indeg[v.second]++;
        } else if (u.first == v.first &&
                   dsu.Find(u.second) != dsu.Find(v.second)) {
          dsu.Union(u.second, v.second);
        }
      }
    }
    FOR(j, 0, n) {
      vector<pii> temp;
      FOR(i, 0, m) temp.push_back({matrix[i][j], i * n + j});
      sort(temp.begin(), temp.end());
      FOR(i, 1, m) {
        pii u = temp[i - 1], v = temp[i];
        if (u.first < v.first) {
          next[u.second].push_back(v.second);
          indeg[v.second]++;
        } else if (u.first == v.first &&
                   dsu.Find(u.second) != dsu.Find(v.second)) {
          dsu.Union(u.second, v.second);
        }
      }
    }
    vector<vector<int>> group(m * n);
    FOR(i, 0, m) {
      FOR(j, 0, n) {
        int idx = i * n + j;
        int root = dsu.Find(idx);
        group[root].push_back(idx);
        if (idx != root) {
          indeg[root] += indeg[idx]; // 同组 找到root,入度要累加
        }
      }
    }
    queue<int> q;
    FOR(i, 0, m) {
      FOR(j, 0, n) {
        int idx = i * n + j;
        if (dsu.Find(idx) == idx && indeg[idx] == 0) { // 入度 0
          q.push(idx);
        }
      }
    }

    int rank = 1;
    auto ans = vector<vector<int>>(m, vector<int>(n, -1));
    while (!q.empty()) {
      int len = q.size();
      while (len--) {
        int cur = q.front();
        q.pop();
        for (auto con : group[cur]) {
          ans[con / n][con % n] = rank; // 同组 同rank
        }
        for (auto conn : group[cur]) {
          for (auto nxt : next[conn]) {
            int root = dsu.Find(nxt);
            indeg[root]--;
            if (indeg[root] == 0) {
              q.push(root);
            }
          }
        }
      }
      rank++;
    }
    return ans;
  }
};
// https://youtu.be/lbN7RBaSYb4?t=896
int main() {
  // 但是有一种情况，就是同一行（列）中，如果有相同的数字，那么他们必须有相同的rank，
  // 因此在拓扑排序中需要把它们当做同一个点来处理。事实上，需要当做同一个点来处理的点可能有多个（而且会分布在不同的row或col里）。
  // 这就需要用union find来将这些点归并到同一个group里。同一个group的点在拓扑排序中只被处理一次，赋值相同的rank。
  //
  //如果用拓扑排序来做，此题比较棘手的地方就是在于处理indegree。我们知道，拓扑排序的每个回合，我们剥离入度为0的点。
  // 在这里，我们需要将所有属于同一个group的点的入度要累加在一块儿计算。当整个group的入度为0的时候，我们才将其加入队列；
  // 当它弹出队列的时候，该group的所有点都赋予相同的rank。然后这些点的剥离会给各自next的点减少一个入度，
  // 但注意，这些入度的自减也必须都统计在整个group上。
  Solution Instance;
  vector<vector<int>> grid = {{1, 2}, {3, 4}};
  vector<vector<int>> ans = Instance.matrixRankTransform(grid);
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] << "\t";
    }
    cout << endl;
  }
  return 0;
};
