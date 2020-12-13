
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    // dual state dp
    int wiggleMaxLength01(vector<int>& nums) {
        const int n = nums.size();
        vector<int> up(n), down(n);
        up[0] = down[0] = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                up[i] = max(up[i - 1], down[i - 1] + 1);
                down[i] = down[i - 1];
            } else if (nums[i] < nums[i - 1]) {
                down[i] = max(down[i - 1], up[i - 1] + 1);
                up[i] = up[i - 1];
            } else {
                up[i] = up[i - 1];
                down[i] = down[i - 1];
            }
        }
        return max(up[n - 1], down[n - 1]);
    }
    int wiggleMaxLength02(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        const int n = nums.size();
        int up = 1, down = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                up = max(up, down + 1);
            } else if (nums[i] < nums[i - 1]) {
                down = max(down, up + 1);
            }
        }
        return max(up, down);
    };
};
int main() {
    Solution INSTANCE;
    vector<int> data = {1, 3, 2, 4, -1, 9, 6, 8};
    cout << INSTANCE.wiggleMaxLength01(data) << "\t"
         << INSTANCE.wiggleMaxLength02(data) << endl;
    return 0;
}