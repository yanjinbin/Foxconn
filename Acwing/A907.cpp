#include <iostream>
#include <vector>
#define pii pair<int, int>
using namespace std;
class Solution {
 public:
  int rangeOverlap(vector<pii> w, pii x) {}
};
int N, l, r;
int main() {
  cin >> l >> r;
  pii x = {l, r};
  cin >> N;
  vector<pii> w;
  while (N--) {
    cin >> l >> r;
    w.push_back({l, r});
  }
  Solution INSTANCE;
  int ans = INSTANCE.rangeOverlap(w, x);
  cout << "区间覆盖" << endl;
  return 0;
}