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

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * b / gcd(a, b); }

class Solution {
public:
  long long wonderfulSubstrings(string word) {
    int n = word.size();
    vector<int> count(1 << 10);// 之前写成n了 不是10 
    int state = 0;
    count[0] = 1; // 初始化
    LL ans = 0;
    for (int i = 0; i < n; i++) {
      int idx = word[i] - 'a';
      state = state ^ (1 << idx);
      ans = ans + count[state];
      for (int i = 0; i < 10; i++) {
        ans = ans + count[state ^ (1 << i)];
      }
      count[state]++;
    }
    return ans;
  }
};
