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

int main() {
  // 每次合并2个最小树，从N树变成N-1树之后，具有最优子结构。
  int n, v;
  cin >> n;
  priority_queue<int, vector<int>, greater<int>> minHeap;
  while (n--) {
    cin >> v;
    minHeap.push(v);
  }
  int ans = 0;
  while (minHeap.size() >= 2) {
    int min1 = minHeap.top();minHeap.pop();
    int min2 = minHeap.top();minHeap.pop();
    int val = min1 + min2;
    minHeap.push(val);
    ans += val;
  }
  cout << ans << endl;
  return 0;
}