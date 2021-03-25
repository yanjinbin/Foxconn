#include <iostream>
#include <vector>
using namespace std;
const int INF = 0X3F3F3F;

class Solution {
   public:
    int longestOnes_01(vector<int>& A, int K) {
        int n = A.size();
        vector<int> preZero(n, 0);
        preZero[0] = A[0] == 0 ? 1 : 0;
        for (int i = 1; i < n; i++) preZero[i] = preZero[i - 1] + A[i];
        vector<vector<int>> dp(n + 1, vector<int>(K + 1, 0));
        int ans = -INF;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= K; j++) {
                if (A[i] == 1) {
                    dp[i][j] = dp[i - 1][j] + 1;
                } else {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
    // 滑动窗口
   public:
    int longestOnes_02(vector<int>& A, int k) {
        int n = A.size();
        int ans = 0;
        vector<int> sum(n + 1, 0);
        for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + A[i];
        for (int i = 0; i < n; i++) {
            int l = 0, r = i;
            while (l < r) {
                int mid = (r - l) / 2 + r;
                if (ok(sum, mid, i, k)) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (ok(sum, r, i, k)) ans = max(ans, i - r + 1);
        }
    }
    bool ok(vector<int> sum, int l, int r, int k) {
        int tot = sum[r + 1] - sum[l], len = r - l + 1;
        return len <= k + tot;
    }

   public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int tot = 0;
        int ans = 0;
        for (int i = 0, j = 0; j < n; j++) {
            tot = tot + nums[j];
            while (j - i + 1 > tot + k) {
                tot = tot - nums[i++];  // 左端点右移
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};

int main() {
    Solution INSTANCE;
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int K = 2;
    cout << INSTANCE.longestOnes(nums, K) << endl;
}