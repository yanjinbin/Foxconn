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
// tag: 设计题 哈希表
class MyHashMap {
private:
  vector<vector<pii>> data;
  static const int base = 779;
  static int hash(int key) { return key % base; }

public:
  MyHashMap() : data(base) {}

  void put(int key, int value) {
    int idx = hash(key);
    for (auto it = data[idx].begin(); it != data[idx].end(); it++) {
      if ((*it).first == key) {
        (*it).second = value; // update
        return;
      }
    }
    // add
    data[idx].PB(MP(key, value));
  }

  int get(int key) {
    int idx = hash(key);
    for (auto it = data[idx].begin(); it != data[idx].end(); it++) {
      if ((*it).first == key) {
        return (*it).second;
      }
    }
    return -1;
  }

  void remove(int key) {
    int h = hash(key);
    for (auto it = data[h].begin(); it != data[h].end(); it++) {
      if ((*it).first == key) {
        data[h].erase(it);
        return;
      }
    }
  }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */