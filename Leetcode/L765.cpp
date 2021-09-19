#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;
const int MAX_VALUE = 0x7FFFFFFF, MIN_VALUE = 0x80000000, INF = 0x3F3F3F3F, kMod = 1E9 + 7;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
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

// tag: union-find  相似题目1202
class Solution {
public:
    int minSwapsCouples(vector<int> &row) {
        int N = row.size();
        parent.resize(N);
        for (int i = 0; i < N; i = i + 2) {
            parent[i] = i;
            parent[i + 1] = i;
        }
        for (int i = 0; i < N; i += 2) {
            int a = row[i];
            int b = row[i + 1];
            if (Find(a) != Find(b)) {
                Union(a, b);
            }
        }
        unordered_map<int, int> count;
        for (int i = 0; i < N; ++i) {
            count[Find(i)]++;
        }
        int ans = 0;
        for (auto x : count) {
            ans += x.second / 2 - 1;
        }
        return ans;
    }

    int Find(int u) {
        if (u != parent[u]) {
            parent[u] = Find(parent[u]);
        }
        return parent[u];
    }

    void Union(int u, int v) {
        int pu = parent[u], pv = parent[v];

        if (pu < pv) {
            parent[pv] = pu;
        } else {
            parent[pu] = pv;
        }
    }

private:
    vector<int> parent;
};