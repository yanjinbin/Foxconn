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
#define ready ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define debug puts("⚡️⚡️bling bling ⚡️⚡️");
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
  vector<int> secondGreaterElement(vector<int> &nums) {
    stack<int> s1, s2;
    vector<int> ans(nums.size(), -1);
    for (int i = 0; i < nums.size(); i++) {
      while (!s2.empty() && nums[s2.top()] < nums[i]) {
        ans[s2.top()] = nums[i];
        s2.pop();
      }

      vector<int> tmp;
      while (!s1.empty() && nums[s1.top()] < nums[i]) {
        tmp.push_back(s1.top());
        s1.pop();
      }
      reverse(tmp.begin(), tmp.end());
      for (auto x : tmp) {
        s2.push(x);
      }

      s1.push(i);
    }
    return ans;
  }
};