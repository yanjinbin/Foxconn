// Google Kickstart2019 Round B Problem B
#include <iostream>
#include <vector>
using namespace std;
int T, N, s, e, l;

class Solution {
 public:
  int energy(vector<vector<int>> w) {}
};

int main() {
  cin >> T;
  Solution Instance;
  while (T--) {
    cin >> N;
    vector<vector<int>> w(N);
    while (N--) {
      cin >> s >> e >> l;
      w.push_back({s, e, l});
    }
    int ans = Instance.energy(w);

  }
  return 0;
}