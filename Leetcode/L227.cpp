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
class Solution {
public:
  int calculate(string str) {
    stack<int> s;
    int ans = 0, sign = 1, num = 0, n = str.size();
    char op = '+';
    unordered_set<char> ops = {'+', '-', '*', '/'};
    for (int i = 0; i < n; i++) {
      char c = str[i];
      if (c >= '0' && c <= '9') {
        num = num * 10 + (c - '0');
      }
      if (ops.find(c) != ops.end() || i == n - 1) {
        if (op == '+')
          s.push(num);
        if (op == '-')
          s.push(-num);
        if (op == '*') {
          int tmp = s.top() * num;
          s.pop();
          s.push(tmp);
        }
        if (op == '/') {
          int tmp = s.top() / num;
          s.pop();
          s.push(tmp);
        }
        // reset
        op = c;
        num = 0;
      }
    }
    while (!s.empty()) {
      ans = ans + s.top();
      s.pop();
    }
    return ans;
  }
};