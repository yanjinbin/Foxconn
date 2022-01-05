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

class Solution {
public:
  int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills, int strength) {
    sort(tasks.begin(), tasks.end());
    sort(workers.begin(), workers.end());
    int left = 0, right = tasks.size();
    while (left < right) {
      int mid = right - (right - left) / 2;
      if (ok(tasks, workers, pills, strength, mid)) {
        left = mid;
      } else {
        right = mid - 1;
      }
    }
    return left;
  }

  bool ok(vector<int> &tasks, vector<int> &workers, int pills, int strength, int num) {
    if (num > tasks.size())
      return false;
    if (num > workers.size())
      return false;
    multiset<int> Set(workers.begin(), workers.end());
    for (int i = num - 1; i >= 0; i--) {
      if (*Set.rbegin() >= tasks[i]) {
        Set.erase(prev(Set.end()));
      } else {
        if (pills == 0)
          return false;
        auto iter = Set.lower_bound(tasks[i] - strength);
        if (iter == Set.end())
          return false;
        pills--;
      }
    }
    return true;
  }
};