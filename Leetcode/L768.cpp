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

// https://bit.ly/3T3B6ij
class Solution {
public:
  // 方法二：单调栈
  // 根据题目，我们可以发现，从左到右，每个分块都有一个最大值，并且这些分块的最大值呈单调递增。
  // 我们可以用一个栈来存储这些分块的最大值。最后得到的栈的大小，也就是题目所求的最多能完成排序的块。
  // 是分成最多的块  因此 arr = [1,0,2,3,4] 是 4 块
  int maxChunksToSorted(vector<int> &arr) {
    stack<int> s;
    for (int i = 0; i < arr.size(); i++) {
      if (s.empty() || arr[i] >= s.top()) {
        s.push(arr[i]);
      } else {
        int mx = s.top();
        s.pop();
        while (!s.empty() && s.top() > arr[i]) {
          s.pop();
        }
        s.push(mx);
      }
    }

    return s.size();
  }
};
