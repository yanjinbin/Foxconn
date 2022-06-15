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
  int smallestDistancePair(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int l = 0, len = nums.size(), r = nums.back() - nums.front() + 1;
    while (l < r) {
      int mid = (r - l) / 2 + l;

      int j = 0, count = 0;
      for (int i = 0; i < len; i++) {
        while (j < len && nums[j] - nums[i] <= mid)
          j++;
        count += j - 1 - i;
      }

      if (count < k) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    return l;
  }
};