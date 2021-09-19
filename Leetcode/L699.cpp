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

// tag: segment tree 线段树+离散化

class Solution {
public:
    // https://youtu.be/d7kSgkC32uY
    vector<int> fallingSquares(vector<vector<int>> &positions) {

    }


    // https://youtu.be/UeuV-6Ygxs4 花花酱  01 02 答案
    vector<int> _fallingSquares01(vector<vector<int>> &positions) {
        vector<int> ans;
        map<pii, int> map;
        int max_height = MIN_VALUE;
        for (vector<int> ele:positions) {
            int st = ele[0], ed = ele[0] + ele[1];
            auto it = map.upper_bound({st, ed});
            // 这里还是没看懂 https://youtu.be/UeuV-6Ygxs4?t=887
            if (it != map.begin()) {
                auto it2 = it;
                if ((--it2)->FI.SE > st)it = it2;
            }
            int base = 0;
            vector <vector<int>> ranges;// shrink的区间
            while (it != map.end() && it->FI.FI < ed) {
                int s = it->FI.FI;
                int e = it->FI.SE;
                int h = it->SE;
                // shrink的区间
                if (s < st)ranges.EB(vector < int > {s, st, h});
                if (e > ed)ranges.EB(vector < int > {ed, e, h});
                base = max(base, h);
                it = map.erase(it);// update iterator  ⭐
            }
            // UPDATE
            int newH = base + ele[1];
            map[{st, ed}] = newH;
            for (vector<int> range:ranges) {
                map[{range[0], range[1]}] = range[2];
            }
            max_height = max(max_height, newH);
            ans.EB(max_height);
        }
        return ans;
    }

    // brute force O(n²)
    vector<int> _fallingSquares02(vector<vector<int>> &positions) {
        vector<int> ans;
        vector <Range> intervals;
        int maxHeight = MIN_VALUE;
        for (vector<int> ele:positions) {
            int st = ele[0], ed = ele[0] + ele[1];
            int baseHeight = 0;
            for (Range range:intervals) {
                if (range.ed <= st || range.st >= ed)continue;
                baseHeight = max(baseHeight, range.height);
            }
            int height = baseHeight + ele[1];
            intervals.EB(Range(st, ed, height));
            maxHeight = max(maxHeight, height);
            ans.EB(maxHeight);
        }
        return ans;
    }

private:
    struct Range {
        int st, ed, height;

        Range(int start, int end, int height) : st(start), ed(end), height(height) {}
    };
};