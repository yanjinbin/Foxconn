#include <algorithm>
#include <cmath>
#include <cstdlib>
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
#define debug puts("⚡️⚡️");
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
  int triangleNumber(vector<int> &nums) {
    int ans = 0;
    int n = nums.size();
    if (n <= 2)
      return 0;
    sort(nums.rbegin(), nums.rend());
    for (int c = 0; c < n - 2; c++) {
      int b = c + 1;
      int a = n - 1;
      while (b < a) {
        if (nums[a] + nums[b] > nums[c]) {
          ans += a - b;
          b++;
        } else {
          a--;
        }
      }
    }
    return ans;
  }
};
