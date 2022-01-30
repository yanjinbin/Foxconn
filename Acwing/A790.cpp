#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

const int MAX_VALUE = 0x7FFFFFFF, MIN_VALUE = 0x80000000, INF = 0x3F3F3F3F,
          kMod = 1E9 + 7;
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define debug puts("⚡️⚡️");
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define pii pair<int, int>
#define LL long long
#define LD long double
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second

double cube(double x) {
  return x * x * x;
}

int main() {
  int N;
  cin >> N;
  double l, r, mid;
  l = -10000, r = 1000;
  while (r - l >= 1E-9) {
    mid = (r - l) / 2 + l;
    if (cube(mid) >= N) {
      r = mid;
    } else {
      l = mid - 1E-9;
    }
  }
  cout << fixed << setprecision(6) << l;
  return 0;
}