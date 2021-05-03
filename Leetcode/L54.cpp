#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include <stack>

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

// 螺旋打印
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &mat) {
        int up = 0, down = mat.size() - 1, left = 0, right = mat[0].size() - 1;
        vector<int> ans;
        while (up <= down && left <= right) {
            // 左->右
            for (int i = left; i <= right; i++) {
                ans.EB(mat[up][i]);
            }
            up++;

            // 上->下
            for (int i = up; i <= down; i++) {
                ans.EB(mat[i][right]);
            }
            right--;

            if (up <= down) {
                for (int i = right; i >= left; i--) {
                    ans.EB(mat[down][i]);
                }
            }
            down--;
            if (left <= right) {
                for (int i = down; i >= up; i--) {
                    ans.EB(mat[i][left]);
                }
            }
            left++;
        }
        return ans;
    }
};