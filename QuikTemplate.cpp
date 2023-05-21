#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int MAX_VALUE = 0x7FFFFFFF, MIN_VALUE = 0x80000000, INF = 0x3F3F3F3F,
          kMod = 1E9 + 7;
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

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * b / gcd(a, b); }
int lowBit(int x) { return x & (-x + 1); }  // 返回二进制右边第一位1
struct ListNode {
  int val;
  ListNode *next;
  ListNode()
      : val(0), next(nullptr){} * ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class UnionFind {
  UnionFind(int n) {
    vector<int> fa(n + 1);
    vector<int> rank(n + 1);
    for (int i = 0; i < fa.size(); i++) {
      fa[i] = i;
      rank[i] = 1;
    }
  }

 public:
  vector<int> fa;
  vector<int> rank;
  int Find(int u) {
    if (u != fa[u]) {
      fa[u] = Find(fa[u]);
    }
    return fa[u];
  }
  bool Union(int u, int v) {
    int x = Find(u);
    int y = Find(v);
    if (x == y) return false;
    if (rank[x] > rank[y]) {
      fa[y] = x;
    } else if (rank[x] < rank[y]) {
      fa[x] = y;
    } else {
      fa[x] = y;
      rank[x]++;
    }
    return true;
  }
};