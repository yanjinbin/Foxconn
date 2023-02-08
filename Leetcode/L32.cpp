#include "../QuikTemplate.cpp"

class Solution {
public:
  int longestValidParentheses(string s) {
    int ans = 0;
    int len = s.size();
    vector<int> dp(len, 0);
    for (int i = 1; i < len; ++i) {
      if (s[i] == ')') {
        if (s[i - 1] == '(') {
          dp[i] = (i - 2 >= 0 ? dp[i - 2] : 0) + 2;
        }
        if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
          dp[i] = dp[i - 1] + 2 + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0);
        }
      }
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};
