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
#include <cstdlib>

using namespace std;

const int MAX_VALUE = 0x7FFFFFFF, MIN_VALUE = 0x80000000, INF = 0x3F3F3F3F, kMod = 1E9 + 7;
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define debug puts("⚡️⚡️");
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define pii pair<int, int>
#define LL long long
#define LD long double
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second

class Solution {
  vector<int> q;
  vector<vector<int>> rects;

public:
  Solution(vector<vector<int>> &rects) {
    int sum = 0;
    for (int i = 0; i < rects.size(); i++) {
      sum += (rects[i][2] - rects[i][0] + 1) * (rects[i][3] - rects[i][1] + 1);
      q.push_back(sum);
    }
    this->rects = rects;
  }

  vector<int> pick() {
    int idx = rand() % q.back()+1;
    int i= lower_bound(q.begin(),q.end(),idx)-q.begin();
    int d1 = rects[i][2]-rects[i][0]+1;
    int d2 = rects[i][3]-rects[i][1]+1;
    int j = rand()%d1;
    int k = rand()%d2;
    return {rects[i][0]+j,rects[i][1]+k}
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */