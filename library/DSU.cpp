#include <vector>

using namespace std;

class DSU {
 public:
  DSU(int n) {
    rank = vector<int>(n + 1, 0);
    parent = vector<int>(n + 1, 0);
    for (int i = 0; i <= n; i++) {
      parent[i] = i;
    }
  }

 public:
  int Find(int u) {
    if (u != parent[u]) {
      parent[u] = Find(parent[u]);
    }
    return parent[u];
  }
  bool Union(int u, int v) {
    int pu = Find(u), pv = Find(v);
    if (pu == pv) return false;
    if (rank[pv] < rank[pu]) {
      parent[pv] = pu;
    } else if (rank[pv] > rank[pu]) {
      parent[pu] = pv;
    } else {
      parent[pu] = pv;
      rank[pv]++;
    }
    return true;
  }

 private:
  vector<int> parent;
  vector<int> rank;
};
