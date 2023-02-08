#include "../QuikTemplate.cpp"

// tag:SegmentTree/线段树
class Solution {
  class SegTree {
  public:
    int st, ed, status;
    SegTree *left;
    SegTree *right;

    SegTree(int start, int end, int status) : st(start), ed(end), status(status), left(nullptr), right(nullptr){};

    void remove(SegTree *node) {
      if (node == nullptr)
        return;
      remove(node->left);
      remove(node->right);
      delete node;
      node = nullptr;
      return;
    }

    void setStatus(int a, int b, int s) {
      if (a >= ed || b < st)
        return;
      if (a <= st && b >= ed && s > status) {
        remove(left);
        remove(right);
        status = s;
        return;
      }
      if (a <= st && b >= ed && s < status && left == nullptr) {
        return;
      }
      if (left == nullptr) {
        int mid = (ed - st) >> 1 + st;
        left = new SegTree(st, mid, status);
        right = new SegTree(mid, ed, status);
      }
      left->setStatus(a, b, s);
      right->setStatus(a, b, s);
      status = max(left->status, right->status);
    }
  };

public:
  vector<vector<int>> results;

  vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
    if (buildings.size() == 0)
      return {};
    SegTree *root = new SegTree(0, MAX_VALUE, 0);
    for (auto p : buildings) {
      root->setStatus(p[0], p[1], p[2]);
    }
    DFS(root);
    if (results.back()[1] != 0) {
      results.PB({MAX_VALUE, 0});
    }
    vector<vector<int>> filters;
    for (auto p : results) {
      if (filters.size() != 0 && p[1] == filters.back()[1])
        continue;
      filters.PB({p[0], p[1]});
    }
    if (filters.size() != 0 && filters[0][1] == 0)
      filters.erase(filters.begin());
    return filters;
  }

  void DFS(SegTree *root) {
    if (root->left == nullptr) {
      results.PB({root->st, root->st});
    } else {
      DFS(root->left);
      DFS(root->right);
    }
  }
};

int main() { return 0; }