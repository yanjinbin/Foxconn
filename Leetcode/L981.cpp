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

// tag:  设计题 时间存储 类似 1146 时间数组快照
class TimeMap {
private:
  unordered_map<string, map<int, string>> d_;

public:
  TimeMap() {}

  void set(string key, string value, int timestamp) { d_[key].emplace(timestamp, value); }

  string get(string key, int timestamp) {
    auto m = d_.find(key);
    if (m == d_.end())
      return "";
    auto it = m->second.upper_bound(timestamp);
    if (it == m->second.begin())
      return "";
    return prev(it)->second;
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */