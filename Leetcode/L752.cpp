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
    int openLock(vector<string> &deadends, string target) {
        set <string> seen(deadends.begin(), deadends.end());
        queue <string> q;
        string start = "0000";
        if (seen.count(start)) return -1;
        if (start == target) return 0;
        q.push(start);
        int level = 0;
        while (!q.empty()) {
            level++;
            int len = q.size();
            for (int i = 0; i < len; i++) {
                const string cur = q.front();
                q.pop();
                for (int j = 0; j < 4; j++) {
                    for (int k = -1; k <= 1; k += 2) {// iteration 2 times
                        string nextRet = cur;
                        nextRet[j] = ((cur[j] - '0' + k + 10) % 10) + '0'; //  k [-1,1] 代表上下旋转
                        if (nextRet == target) return level;
                        if (seen.count(nextRet)) continue;
                        q.push(nextRet);
                        seen.insert(nextRet);
                    }
                }
            }
        }
        return -1;
    }
};