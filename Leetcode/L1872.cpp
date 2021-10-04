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

// 石头游戏 game theory/ min-max O（N）  花花酱对石子游戏系列有做总结 https://youtu.be/5EaopigkqUc
class Solution {
public:
  int stoneGameVIII(vector<int> &stones) {
    int n = stones.size();
    for (int i = 1; i < n; ++i) {
      stones[i] += stones[i - 1];
    }
    int ans = stones.back();
    for (int i = n - 1; i >= 2; i--) {
      ans = max(ans, stones[i - 1] - ans);
    }
    return ans;
  }
};
