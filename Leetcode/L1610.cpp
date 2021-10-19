#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

const int INF = 0x3F3F3F3F;
const int MOD = 1E9 + 7;
#define ready                                                                                                          \
  ios_base::sync_with_stdio(false);                                                                                    \
  cin.tie(0);                                                                                                          \
  cout.tie(0);
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
  int visiblePoints(vector<vector<int>> &points, int angle, vector<int> &loc) {
    int at_origin = 0;
    double PI = 3.1415926;
    vector<double> ps;
    for (const auto &p : points) {
      if (p[0] == loc[0] && p[1] == loc[1]) {
        at_origin++;
      } else {
        ps.EB(atan2(p[1] - loc[1], p[0] - loc[0]));
      }
    }
    sort(ps.begin(), ps.end());
    const int n = ps.size();
    for (int i = 0; i < n; i++)
      ps.EB(ps[i] + 2.0 * PI); // 扩大2倍
    int l = 0, ans = 0;
    double fov = angle * PI / 180.0;
    for (int r = 0; r < ps.size(); r++) {
      while (ps[r] - ps[l] > fov)
        l++;
      ans = max(ans, r - l + 1);
    }
    return ans + at_origin;
  }
};