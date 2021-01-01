#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
const int INF = 0x3F3F3F3F;
#define debug puts("pigtoria bling bling ⚡️⚡️");
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

//  证明参见https://www.acwing.com/solution/content/8130/
int main() {
  int n;
  cin >> n;
  vector<int> arr(n + 1);
  FOR(i,1,n+1) cin >> arr[i];
  sort(arr.begin()+1,arr.end());
  int ans = 0;
  FOR(i,1,n+1) ans += abs(arr[i]-arr[(n+1)/2]);
  cout << ans << endl;
  return 0;
}