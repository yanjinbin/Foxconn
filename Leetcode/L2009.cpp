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

// 排序 去重+(二分加快查找)
class Solution {
public:
  int minOperations(vector<int> &nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    int ans = 0X3F3F3F3F;
    for (int i = 0; i < nums.size(); i++) {
      int t = nums[i] + n - 1;
      int left = upper_bound(nums.begin(), nums.end(), t) - nums.begin();
      ans = min(ans, n - (left - i));
    }
    return ans;
  }
};