#include <algorithm>
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
#define fastio                                                                                                                                                                                         \
  ios_base::sync_with_stdio(false);                                                                                                                                                                    \
  cin.tie(0);                                                                                                                                                                                          \
  cout.tie(0);
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

class Solution {
public:
  int minimumSize(vector<int> &nums, int maxOperations) {
    // https://www.bilibili.com/video/BV1bK4y1H7Ly
    int l = 1, r = *max_element(nums.begin(), nums.end()) + 1;
    while (l < r) {
      int m = l + (r - l) / 2;
      int ops = 0;
      for (int x : nums) {
        ops += (x + m - 1) / m - 1; // 向上取整-1
      }
      if (ops > maxOperations) { // 返回≤的l
        l = m + 1;
      } else {
        r = m;
      }
    }
    return l;
  }
};

int main() {}