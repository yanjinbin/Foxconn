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

// tag: slide windows
// time: O(N)
class Solution {
public:
    int shortestSubarray(vector<int> &A, int K) {
        int N = A.size();
        vector<long> pre(N + 1, 0);
        for (int i = 0; i < N; ++i) {
            pre[i + 1] = pre[i] + (long) A[i];
        }
        int ans = N + 1; // IMPOSSIBLE
        deque<int> monoq; //  mono incr
        for (int k = 0; k <= N; ++k) {
            // 维护单调递增
            while (!monoq.empty() && pre[k] <= pre[monoq.back()]) {
                monoq.pop_back();
            }
            // 移除头部元素 破坏子数组和>=K条件
            while (!monoq.empty() && pre[k] >= pre[monoq.front()] + K) {
                ans = min(ans, k - monoq.front());
                monoq.pop_front();
            }
            monoq.push_back(k);
        }
        return ans < N + 1 ? ans : -1;
    }
};