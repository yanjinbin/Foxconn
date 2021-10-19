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

// tag: 设计题 设计停车系统
class ParkingSystem {
private:
  int s, m, b;

public:
  ParkingSystem(int big, int medium, int small) : s(small), m(medium), b(big) {}

  bool addCar(int carType) {
    if (carType == 1) {
      if (b > 0) {
        b--;
        return true;
      }
    } else if (carType == 2) {
      if (m > 0) {
        m--;
        return true;
      }
    } else if (carType == 3) {
      if (s > 0) {
        s--;
        return true;
      }
    }
    return false;
  }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */