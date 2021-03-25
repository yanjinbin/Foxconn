#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
const int INF = 0x3F3F3F3F;
#define debug puts("pigtoria bling bling ⚡️⚡️");
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ll long long
#define pii pair<int, int>

int main() {
  // https://www.acwing.com/solution/content/845/
  int n;
  cin >> n;
  vector<pii> cow(n);
  int s, w;
  FOR(i, 0, n) {
    cin >> s >> w;
    cow[i].first = s + w;
    cow[i].second = w;
  }
  sort(cow.begin(), cow.end());
  int ans = INT_MIN, sum = 0;
  FOR(i, 0, n) {
    sum -= cow[i].second;
    ans = max(ans, sum);
    sum += cow[i].first;
  }
  cout << ans << endl;
  return 0;
}