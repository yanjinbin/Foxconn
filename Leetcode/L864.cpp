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

class Solution {
public:
    int shortestPathAllKeys(vector<string> &grid) {
        int m = grid.size(), n = grid[0].size();
        int all_keys = 0;
        queue<int> q;
        vector < vector < vector < int>>> seen(m, vector < vector < int >> (n, vector<int>(64, 0)));
        // init
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                const char c = grid[i][j];
                if (c == '@') {
                    q.push((j << 16 | i << 8));
                    seen[i][j][0] = 1;
                } else if (c >= 'a' && c <= 'f') {
                    all_keys |= (1 << (c - 'a'));
                }
            }
        }

        const vector<int> dirs = {-1, 0, 1, 0, -1};
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int state = q.front();
                q.pop();
                int x = state >> 16, y = ((state >> 8) & 0Xff), keys = state & 0XFF;
                if (keys == all_keys)return steps;
                for (int i = 0; i < 4; ++i) {
                    int nkeys = keys;
                    int nx = x + dirs[i];
                    int ny = y + dirs[i + 1];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
                    const char c = grid[ny][nx];
                    if (c == '#')continue;// wall
                    if (c >= 'A' && c <= 'F' && !(keys & (1 << (c - 'A'))))continue;//do not have the key
                    if (c >= 'a' && c <= 'f')nkeys |= (1 << (c - 'a'));// have the key
                    if (seen[ny][nx][keys])continue;
                    q.push((nx << 16) | (ny << 8) | nkeys);
                    seen[ny][nx][keys] = 1;
                }
            }
            steps++;
        }
        return -1;
    }
};
