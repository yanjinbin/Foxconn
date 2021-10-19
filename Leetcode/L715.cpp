#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;
const int MAX_VALUE = 0x7FFFFFFF, MIN_VALUE = 0x80000000, INF = 0x3F3F3F3F, kMod = 1E9 + 7;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
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

// ref:699 218 涉及节点动态开辟
class RangeModule {
private:
  vector<pair<int, int>> ranges_;

public:
  RangeModule() {}

  void addRange(int left, int right) {
    vector<pair<int, int>> _ranges_;
    bool inserted = false;
    for (const auto &kv : ranges_) {
      if (kv.first > right && !inserted) {
        // 补上 之前 overlap 更新后的区间
        _ranges_.emplace_back(left, right);
        inserted = true;
      }
      if (kv.second < left || kv.first >right){
        // not-overlap range
        _ranges_.push_back(kv);
      } else{
        // update overlap 区间
        left = min(left, kv.first);
        right = max(right, kv.second);
      }
    }
    if (!inserted) {
      _ranges_.emplace_back(left, right);
    }
    ranges_.swap(_ranges_);
  }

  bool queryRange(int left, int right) {
    const int n = ranges_.size();
    int l = 0, r = n;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (ranges_[mid].second < left) {
        l = mid + 1;
      } else if (ranges_[mid].first > right) {
        r = mid;
      } else {
        return ranges_[mid].first <= left && right <= ranges_[mid].second;
      }
    }
    return false;
  }

  void removeRange(int left, int right) {
    vector<pair<int, int>> _ranges_;
    for (const auto &kv : ranges_) {
      if (kv.second <= left || kv.first >= right) {
        _ranges_.push_back(kv);
      } else {
        if (kv.first < left)
          _ranges_.emplace_back(kv.first, left);
        if (kv.second > right)
          _ranges_.emplace_back(right, kv.second);
      }
    }
    ranges_.swap(_ranges_);
  }
};

//==============
class RangeList {
public:
  RangeModule() {}

  void addRange(int left, int right) {
    IT st, ed;
    overlapRanges(left, right, st, ed);
    if (st != ed) {
      auto last = ed;
      last--;
      left = min(left, st->first);
      right = max(right, last->second);
      ranges_.erase(st, ed);
    }
    ranges_[left] = right;
  }

  bool queryRange(int left, int right) {
    IT l, r;
    overlapRanges(left, right, l, r);
    // No overlapping range
    if (l == r)
      return false;
    return l->first <= left && l->second >= right;
  }

  void removeRange(int left, int right) {
    IT st, ed;
    overlapRanges(left, right, st, ed);
    if (st == ed)
      return;
    auto last = ed;
    last--;
    int lo = min(left, st->first);
    int hi = max(right, last->second);
    ranges_.erase(st, ed);
    if (lo < left)
      ranges_[lo] = left;
    if (hi > right)
      ranges_[right] = hi;
  }

private:
  typedef map<int, int>::iterator IT;
  map<int, int> ranges_;
  void overlapRanges(int left, int right, IT &st, IT &ed) {
    st = ranges_.upper_bound(left);
    ed = ranges_.upper_bound(right);
    if (st != ranges_.begin()) {
      if ((--st)->second < left) {
        st++;
      }
    }
  }
}
