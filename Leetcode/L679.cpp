#include <algorithm>
#include <climits>
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

// similar-2019  241  tag:经典 递归
class Solution {
public:
  bool judgePoint24(vector<int> &cards) {
    vector<double> nums;
    for (int i = 0; i < cards.size(); i++) {
      nums.PB(cards[i] * 1.0);
    }
    sort(nums.begin(), nums.end());
    while (true) {
      unordered_set<double> rets = helper(nums, 0, nums.size() - 1);
      for (auto x : rets) {
        if (abs(x - 24.0) < 1e-10) { // 精度
          return true;
        }
      }
      if (next_permutation(nums.begin(), nums.end()) == false)
        break;
    }
    return false;
  }
  unordered_set<double> helper(vector<double> &nums, int lo, int hi) {
    if (lo == hi) {
      return {nums[lo]};
    }
    unordered_set<double> rets;
    for (int i = lo; i < hi; i++) {
      unordered_set<double> A = helper(nums, lo, i);
      unordered_set<double> B = helper(nums, i + 1, hi);
      for (auto x : A) {
        for (auto y : B) {
          rets.insert({x + y, x - y, x * y});
          if (y != 0)
            rets.insert(x / y);
        }
      }
    }
    return rets;
  }
};