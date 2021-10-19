#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;
#define debug puts("⚡️⚡️ bling bling ⚡️⚡️");

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define IT iterator
#define pii pair<int, int>
typedef long double ld;
// typedef complex<ld> cd;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
// typedef vector<cd> vcd;

#define sqr(x) ((x) * (x))
#define pi acosl(-1)
#define MEM(x) memset(x, 0, sizeof(x))
#define MEMS(x) memset(x, -1, sizeof(x))
#define CLR(a, v) memset(a, v, sizeof(a));
#define CPY(a, b) memcpy(a, b, sizeof(a));
#define fi first
#define se second
#define mp make_pair
#define pb push_back
const ll INFLL = 1LL << 60;
const int INF = 0x3F3F3F3F, MOD = 1e9 + 7;
const int d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
const int d8i[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
        d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};

// Definition for a point.
struct Point {
  int x;
  int y;

  Point() : x(0), y(0) {}

  Point(int a, int b) : x(a), y(b) {}
};

struct Node {
    int r, c, h;

    bool operator<(const Node &other) const {
        return this->h < other.h;
    }
};

int main() {
  vector<Node> arr = {{1, 2, 3}, {2, 3, 4}, {5, 6, 7}, {3, 4, 5}};
  sort(arr.begin(), arr.end());
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i].h << "\t";
  }

  // 默认大堆
  priority_queue<int> q1;
  q1.push(0);
  q1.push(1);
  q1.push(6);
  cout << endl << q1.top() << endl;

    // 优先队列，是对比较器逆反的过程
  priority_queue<Node> minHeap;
  minHeap.push(Node{1, 2, 9});
    minHeap.push(Node{2, 3, 10});
    minHeap.push(Node{3, 4, 11});
    cout << minHeap.top().h << endl;

    return 0;
}