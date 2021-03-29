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
    // https://bit.ly/3u4H8T6
    int findMin(vector<int> &nums) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = (hi - lo) / 2 + lo; //地板除 lo<=mid , mid < hi
            if (nums[mid] > nums[hi]) {
                lo = mid + 1;
            } else if (nums[mid] < nums[hi]) {
                hi = mid;
            } else {// 处理重复元素
                hi--;
            }
        }
        return nums[lo];
    }
};

int main() {
    Solution INSTANCE;//0  1  2  3  4   5   6
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int ans = INSTANCE.findMin(nums);
    cout << ans << endl;
    return 0;
}