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
#define debug puts("💣 boom bang bling ⚡️⚡️");
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define pii pair<int, int>
#define LL long long
#define LD long double
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
// tag： 单调栈
class Solution {
public:
  string smallestSubsequence(string str, int k, char letter, int repetition) {
    int count = 0;
    for (auto ch : str) {
      if (ch == letter)
        count++;
    }
    int k0 = str.size() - k;
    int k1 = count - repetition;
    int c0 = 0, c1 = 0;
    stack<int> s;
    for (int i = 0; i < str.size(); i++) {
      while (!s.empty() && str[i] < s.top() && c0 < k0 && (s.top() != letter || (s.top() == letter && c1 < k1))) {
        if (s.top() == letter) {
          c1++;
        }
        c0++;
        s.pop();
      }
      s.push(str[i]);
    }

    string ret;
    while (!s.empty()) {
      ret = ret + char(s.top());
      s.pop();
    }
    // 为什么从后往前删除 因为小的排前面 大的排后面 所以当然从后往前删除了 你傻啊!
    string ans;
    for (int i = 0; i < ret.size(); i++) {
      if (c0 == k0 || (ret[i] == letter && c1 == k1)) {
        ans.push_back(ret[i]);
      } else {
        c0++;
        if (ret[i] == letter) {
          c1++;
        }
      }
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};