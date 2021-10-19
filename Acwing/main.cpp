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

int main() {  // https://tinyurl.com/y64wz26k https://tinyurl.com/y5wqw65e
  // lambda表达式
  int a = 123;
  auto fFunc = [&] {  // 值捕获
    cout << a << endl;
  };
  a = 321;
  fFunc();
  //
  auto gFunc = [&a] {
        a = 899;
        cout << a << endl;
    };
    a = 999;
    gFunc();
    int b = 888;
    auto hFunc = [&] {
        cout << a << endl;
        cout << b << endl;
    };
    hFunc();

    auto kFunc = [=] {
        cout << a << "\t" << b << endl;
    };
    kFunc();
    // [capture list] (params list) mutable exception-> return type { function
    // body }
    vector<int> arr = {1, 2, 3, 4, 5, -1};
    sort(arr.begin(), arr.end(), [](int a, int b) -> bool { return a < b; });
    FOR(i, 0, arr.size()) {
      cout << arr[i] << "\t";
    }
    cout << endl;
    auto cmp = [](int a, int b) -> bool { return a > b; };
    sort(arr.begin(), arr.end(), cmp);
    priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
    q.push(5);
    q.push(2);
    q.push(10);
    cout << q.top() << endl;
    set<int, decltype(cmp)> s(cmp);
    s.insert(10);
    s.insert(1);
    s.insert(11);
    s.insert(5);
    for (auto &c : s) {
      cout << c << " ";
    }
    cout << endl;
    map<int, int, decltype(cmp)> m(cmp);
    m[3] = 1;
    m[1] = 2;
    m[10] = 3;
    m[5] = 4;
    for (auto const &item : m) {
      cout << item.first << " | " << item.second << endl;
    }
    cout << endl;

    /* function<int(int, int)> Add = [](int a, int b) -> int {
         return a + b;
     };
     int ans = Add(1, 3);
     cout << ans << endl;
     function<void(int, int)> print_ = [](int a, int b) {
         cout << a + b << endl;
     };
     print_(999, 1);*/

    vector<string> names(5, "hello");
    FOR(i, 0, names.size()) {
        cout << names[i] << " ";
    }
    cout << endl;
    vector<vector<int>> grid(5, vector<int>(5, 1));
    FOR(i, 0, grid.size()) {
        FOR(j, 0, grid[i].size()) {
            cout << grid[i][j] << " | ";
        }
        cout << endl;
    }
    grid.resize(10);
    cout << grid.size() << endl;

    cout << endl;
    FOR(i, 0, grid.size()) {
        FOR(j, 0, grid[i].size()) {
            cout << grid[i][j] << " | ";
        }
        cout << endl;
    }
    cout << "here" << endl;
    if (m[78]) {
        cout << m[78] << endl;
    } else {
        cout << " no exist" << endl;
    }

}
