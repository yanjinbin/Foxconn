#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int missingNumber01(vector<int> &nums) {
        int lo = 0, hi = nums.size();
        while (lo < hi) {
            int mid = (hi - lo) / 2 + lo;
            if (nums[mid] <= mid) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        // 找到nums[mid]>mid的第一个就是我们要的答案
        return lo;
    }


    int missingNumber02(vector<int> &nums) {
        int miss = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            miss ^= nums[i] ^ i;
        }
        return miss;
    }
};

int main() {
    Solution INSTANCE;
    vector<int> nums = {0, 1, 2, 3, 5};
    cout << INSTANCE.getMissingNumber(nums) << endl;
    return 0;
}