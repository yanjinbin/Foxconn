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
#define ready ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define debug puts("⚡️⚡️ bling bling ⚡️⚡️");
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define pii pair<int, int>
#define LL long long
#define LD long double
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second

// https://bit.ly/3DC08jf
//  1 9 [3] 6 2
//  2 8 [5] 6 [5] 1
class Solution {
public:
  int sumSubarrayMins(vector<int> &arr) {
    int n = arr.size();
    // 初始值设置成index n和-1是特定的 有原因的
    // 参见 https://youtu.be/TZyBPy7iOAw?t=978
    vector<int> nextSmaller(n, n);
    vector<int> prevSmaller(n, -1);
    stack<int> s1;
    for (int i = 0; i < n; i++) {
      while (!s1.empty() && arr[s1.top()] > arr[i]) {
        nextSmaller[s1.top()] = i;
        s1.pop();
      }
      s1.push(i);
    }

    stack<int> s2;
    for (int i = n - 1; i >= 0; i--) {
      while (!s2.empty() && arr[s2.top()] >= arr[i]) {
        prevSmaller[s2.top()] = i;
        s2.pop();
      }
      s2.push(i);
    }

    long ans = 0;
    for (int i = 0; i < n; i++) {
      long count = (i - prevSmaller[i]) % kMod * (nextSmaller[i] - i) % kMod;
      ans = (ans + count * arr[i]) % kMod;
    }
    return ans;
  }
};