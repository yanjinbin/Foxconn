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

// tag: bitmask hashTable
class Solution {
public:
  int longestAwesome(string s) {
    // 2的10次（0-9 奇偶状态位表示）
    vector<int> idx(1024, INF);
    idx[0] = -1; // 初始mask idx[0] = -1 设置为-1,覆盖 cornercase 输入的 s
    // 本身就是回文串
    int mask = 0, ans = 0;
    for (int i = 0; i < s.size(); i++) {
      mask ^= (1 << (s[i] - '0'));
      ans = max(ans, i - idx[mask]);
      // 只允许一位奇数位数字, 尝试更新 获取
      for (int j = 0; j < 10; j++) {
        ans = max(ans, i - idx[mask ^ (1 << j)]);
      }
      // 更新  mask,idx 出现的位次，取最小！
      idx[mask] = min(idx[mask], i);
    }
    return ans;
  }
};
