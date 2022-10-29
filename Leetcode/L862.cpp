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

// tag: slide windows
// time: O(N)
class Solution {
public:
  int shortestSubarray(vector<int> &A, int K) {
    int N = A.size();
    vector<long> preSum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
      preSum[i + 1] = preSum[i] + (long)A[i];
    }
    int ans = N + 1;  // IMPOSSIBLE
    deque<int> incrQ; //  mono incr
    for (int k = 0; k <= N; ++k) {
      // 维护单调递增
      while (!incrQ.empty() && preSum[k] <= preSum[incrQ.back()]) {
        incrQ.pop_back();
      }
      // 移除头部元素 破坏子数组和>=K条件
      while (!incrQ.empty() && preSum[k] - preSum[incrQ.front()] >= K) {
        ans = min(ans, k - incrQ.front());
        incrQ.pop_front();
      }
      incrQ.push_back(k);
    }
    return ans < N + 1 ? ans : -1;
  }
};