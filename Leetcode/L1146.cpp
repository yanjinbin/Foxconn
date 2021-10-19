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

// tag: 设计题  时间数组快照 vector map
class SnapshotArray {
private:
  int id_;
  vector<map<int, int>> dicts;

public:
  SnapshotArray(int length) : id_(0), dicts(length) {}

  void set(int index, int val) { dicts[index][id_] = val; }

  int snap() { return id_++; }

  int get(int index, int snap_id) {
    auto it = dicts[index].upper_bound(snap_id);
    if (it == dicts[index].begin())
      return 0;
    else
      return prev(it)->second;
  }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj-≤>snap();
 * int param_3 = obj->get(index,snap_id);
 */