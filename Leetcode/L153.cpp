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


class Solution {
public:
    int findMin(vector<int> &arr) {
        if (arr.size() == 1) return arr[0];
        int lo = 0, hi = arr.size() - 1;
        if (arr[hi] > arr[lo])return arr[0];
        while (lo <= hi) {
            int mid = (hi - lo) / 2 + lo;
            // 搜索停止
            if (arr[mid] > arr[mid + 1])return arr[mid + 1];
            if (arr[mid - 1] > arr[mid])return arr[mid];

            if (arr[mid] > arr[0]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return -1;
    }

    // https://bit.ly/3u4H8T6
    int findMin_(vector<int> &arr) {
        int lo = 0, hi = arr.size() - 1;
        while (lo < hi) {
            int mid = (hi - lo) / 2 + lo;
            if (arr[mid] > arr[hi]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return arr[lo];
    }
};