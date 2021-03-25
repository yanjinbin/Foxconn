#include <algorithm>
#include <iostream>
#include <vector>

#define pii pair<int, int>
using namespace std;

const int INF = 0x3F3F3F3F;

class Solution {
 public:
  int range(vector<pii> data) {
    sort(data.begin(), data.end(),
         [](pii p, pii q) -> bool { return p.second < q.second; });
    int ans = 0;
    int end = -INF;
    const int len = data.size();
    for (int i = 0; i < len; i++) {
      if (end < data[i].first) {
        ans++;
        end = data[i].second;
      }
    }
    return ans;
  }
};

int N;
int l, r;

int main() {
  // Acwing 905 908答案
  cin >> N;
  vector<pii> data;
  while (N--) {
    cin >> l >> r;
    data.push_back({l, r});
  }
  Solution INSTANCE;
  int ans = INSTANCE.range(data);
  cout << ans;
  return 0;
}