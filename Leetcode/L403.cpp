#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include <stack>
#include <numeric>
#include <set>
#include <unordered_set>

using namespace std;

const int MAX_VALUE = 0x7FFFFFFF, MIN_VALUE = 0x80000000, INF = 0x3F3F3F3F, kMod = 1E9 + 7;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define debug puts("⚡️⚡️ bling bling ⚡️⚡️");
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

    unordered_set<int> seen;
    set<pair<int, int>> failed; // 记忆化
public:
    bool canCross(vector<int> &stones) {
        for (auto x:stones) {
            seen.insert(x);
        }
        return dfs(stones, 0, 0);
    }

    bool dfs(vector<int> &stones, int pos, int jump) {
        if (pos == stones.back()) return true;
        if (!seen.count(pos)) return false;
        if (failed.count({pos, jump}))return false;
        if (jump > 1 && dfs(stones, pos + jump - 1, jump - 1)) {
            return true;
        }
        if (jump > 0 && dfs(stones, pos + jump, jump)) {
            return true;
        }
        if (dfs(stones, pos + jump + 1, jump + 1)) {
            return true;
        }
        failed.insert({pos, jump});
        return false;
    }


};