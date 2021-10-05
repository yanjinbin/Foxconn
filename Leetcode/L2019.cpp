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
  // 241和227的组合运用
private:
  vector<int> nums;
  vector<char> ops;
  unordered_set<int> dp[21][21];

public:
  int scoreOfStudents(string expr, vector<int> &answers) {
    for (int i = 0; i < expr.size(); i++) {
      int j = i;
      while (j < expr.size() && isdigit(expr[j])) {
        j++;
      }
      nums.PB(stoi(expr.substr(i, j - i)));
      if (j < expr.size())
        ops.PB(expr[j]);
      i = j; // 别忘记更新j
    }
    int rightAns = calculate227(expr);

    int n = nums.size();

    helper(0, n - 1);
    int ret = 0;
    for (auto ans : answers) {
      if (ans == rightAns)
        ret += 5;
      else if (dp[0][n - 1].find(ans) != dp[0][n - 1].end())
        ret += 2;
    }
    return ret;
  }

  void helper(int lo, int hi) {
    if (!dp[lo][hi].empty())
      return;
    if (lo == hi) {
      dp[lo][hi] = {nums[lo]};
      return;
    }
    for (int k = lo; k < hi; k++) {
      helper(lo, k);
      helper(k + 1, hi);
      for (auto x : dp[lo][k])
        for (auto y : dp[k + 1][hi]) {
          if (ops[k] == '+' && x + y <= 1000)
            dp[lo][hi].insert(x + y);
          else if (ops[k] == '*' && x * y <= 1000)
            dp[lo][hi].insert(x * y);
        }
    }
  }

  int calculate227(string str) {
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