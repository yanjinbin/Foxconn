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
#include <climits>

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

class Solution {
public:
    long long maxAlternatingSum(vector<int> &nums) {
        LL ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i + 1 < nums.size() && nums[i] > nums[i + 1]) {
                ans += nums[i] - nums[i + 1];
            }
        }
        ans += nums.back();
        return ans;
    }

    long long maxAlternatingSum_(vector<int> &nums) {
      int n = nums.size();
      vector<vector<LL>> f(n, vector<LL>(2, 0));
      f[0][0] = nums[0];
      f[0][1] = 0;
      for (int i = 1; i < nums.size(); ++i) {
        f[i][0] = max(f[i - 1][0], f[i - 1][1] + nums[i]);
        f[i][1] = max(f[i - 1][1], f[i - 1][0] - nums[i]);
      }
      return max(f[n - 1][0], f[n - 1][1]);
    }
};