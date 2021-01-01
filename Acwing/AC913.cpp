#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
const int INF = 0x3F3F3F3F;

#define debug puts("pigtoria bling bling ⚡️⚡️");
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  int val;
  FOR(i, 0, n) cin >> arr[i];
  sort(arr.begin(), arr.end());
  partial_sum(arr.begin(), arr.end(), arr.begin());
  long ans = 0;
  for (int i = 0; i < n - 1; i++) {
    ans += arr[i];
  }
  cout << ans << endl;
}