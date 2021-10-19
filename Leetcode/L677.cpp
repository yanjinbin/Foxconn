#include <algorithm>
#include <climits>
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

// tag: 设计题
class MapSum {
private:
  struct Trie {
    Trie() : children(26, nullptr), sum(0){};
    ~Trie() {
      for (auto child : children) {
        if (child)
          delete child;
      }
      children.clear();
    }
    vector<Trie *> children;
    int sum;
  };
  Trie root; // dummy root
  unordered_map<string, int> vals_;

public:
  MapSum() {}

  void insert(string key, int val) {
    int delta = val - vals_[key];
    Trie *p = &root;
    for (auto c : key) {
      if (!p->children[c - 'a'])
        p->children[c - 'a'] = new Trie();
      p->children[c - 'a']->sum += delta; // update sum
      p = p->children[c - 'a'];           // level down
    }
    vals_[key] = val;
  }

  int sum(string prefix) {
    Trie *p = &root;
    for (const char c : prefix) {
      if (!p->children[c - 'a'])
        return 0;
      else
        p = p->children[c - 'a'];
    }
    return p->sum;
  }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */