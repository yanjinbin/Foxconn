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
#include <climits>

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

// related->864
class Solution {
public:
    int shortestPathLength(vector<vector<int>> &graph) {
        int n = graph.size();
        int finalState = (1 << n) - 1;
        queue <pii> q;//(node 当前访问节点,state已经访问过的节点
        vector <vector<bool>> seen(n, vector<bool>(1 << n, false));
        for (int i = 0; i < n; i++) {
            q.push(pii{i, 1 << i});
            seen[i][1 << i] = true;
        }
        int step = -1;
        while (!q.empty()) {
            step++;
            int len = q.size();
            while (len--) {
                int node = q.front().first;
                int state = q.front().second;
                q.pop();
                for (int nextNode:graph[node]) {
                    int newState = state | (1 << nextNode);
                    if (seen[nextNode][newState]) continue;
                    if (newState == finalState) return step + 1;
                    q.push(pii{nextNode, newState});
                    seen[nextNode][newState] = true;
                }
            }
        }
        return 0;

    }
};