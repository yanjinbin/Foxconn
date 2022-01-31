#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

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

// Topology sort
class Solution {
public:
  vector<string>
  findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies) {
    unordered_map<string, vector<string>> G;
    unordered_map<string, int> indegree;
    for (int i = 0; i < recipes.size(); i++) {
      string v = recipes[i];
      for (int j = 0; j < ingredients[i].size(); j++) {
        string u = ingredients[i][j];
        G[u].push_back(v);
        indegree[v] += 1;
      }
    }
    queue<string> q;
    for (string s : supplies) {
      q.push(s);
    }
    unordered_set<string> wanted(recipes.begin(), recipes.end());
    vector<string> ans;
    while (!q.empty()) {
      string cur = q.front();
      q.pop();
      if (wanted.find(cur) != wanted.end()) {
        ans.push_back(cur);
      }
      for (auto x : G[cur]) {
        indegree[x] -= 1;
        if (indegree[x] == 0) {
          q.push(x);
        }
      }
    }
    return ans;
  }
};