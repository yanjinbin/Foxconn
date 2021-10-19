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
const int MAX_VALUE = 0x7FFFFFFF, MIN_VALUE = 0x80000000, INF = 0x3F3F3F3F,
          kMod = 1E9 + 7;
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
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

int main() {
  auto comp = [](tuple<int, double, string> p,
                 tuple<int, double, string> q) -> bool {
    int x1 = get<0>(p), x2 = get<0>(q);
    double y1 = get<1>(p), y2 = get<1>(q);
    string z1 = get<2>(p), z2 = get<2>(q);
    return x1 != x2 ? x1 < x2 : (y1 != y2 ? y1 < y2 : (z1 < z2));
  };
  vector<tuple<int, double, string>> tups;
  int N;
  int x;
    double y;
    string z;
    cin >> N;
    while (N--) {
        cin >> x >> y >> z;
        tups.push_back(tie(x, y, z));
    }
    // priority_queue<tuple<int,double,string>,comp()> pq;
    sort(tups.begin(), tups.end(), comp);
    for (int i = 0; i < tups.size(); i++) {
        tuple<int, double, string> t = tups[i];
        printf("%d %.2lf %s\n", get<0>(t), get<1>(t), get<2>(t).c_str());
    }
}