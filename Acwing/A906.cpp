#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define pii pair<int, int>
using namespace std;

// 题解参考  https://www.acwing.com/solution/content/14773/
// 当时想错的原因是 没读懂题意， 两两不相交的 区间组 的 个数 两两不相交和 组
class Solution {
 public:
  int rangeGroup(vector<pii> w) {
    sort(w.begin(), w.end(),
         [](pii p, pii q) -> bool { return p.first < q.first; });
    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 0; i < w.capacity(); i++) {
      pii p = w[i];
      if (heap.empty() ||
          heap.top() >= p.first) {  // 最小组的区间的右端点 >=
                                    // 当前区间的左端点，那么就要再新开一个组了
        heap.push(p.second);
      } else {  // 说明 当前区间和最小组的区间
                // 不想交，那么可以放到当前最小区间组种，并 pop 最小的
        // 更新成当前区间的右端点值
        heap.pop();
        heap.push(p.second);
      }
    }
    return heap.size();
  }
};

int N;

int main() {
  cin >> N;
  vector<pii> w;
  while (N--) {
    int l, r;
    cin >> l >> r;
    w.push_back({l, r});
  }
  Solution INSTANCE;
  int ans = INSTANCE.rangeGroup(w);
  cout << ans;
  return 0;
}