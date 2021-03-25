#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include <stack>

using namespace std;

const int INF = 0x3F3F3F3F;
const int MOD = 1E9 + 7;
#define ready ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
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

// 类似 AC907 区间覆盖问题 https://www.acwing.com/problem/content/909/
class Solution {
public:
    int minTaps(int n, vector<int> &ranges) {
        vector <pii> vp;
        for (int i = 0; i < ranges.size(); ++i) {
            vp.EB(make_pair(i - ranges[i], i + ranges[i]));
        }
        sort(vp.begin(), vp.end());
        int ans = 0;
        bool success = false;
        int len = vp.size();
        int i = 0;
        int st = 0, ed = n;
        while (i < len) {
            int j = i, r = -INF;
            while (j < len && vp[j].first <= st) {
                r = max(r, vp[j].second);
                j++;
            }
            if (r < st) {
                ans = -1;
                break;
            }
            ans++;
            if (r>=ed){
                success = true;
                break;
            }
            st=r;
            i=j;
        }
        if (success) return ans;
        else return -1;
    }
};
