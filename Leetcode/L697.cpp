#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
   public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, vector<int>> m;
        int freq = 0, mx = 0;
        for (int i = 0; i < nums.size(); i++) {
            int key = nums[i];
            if (m.count(key)) {
                m[key][0]++;
                m[key][2] = i;
            } else {
                m[key] = {1, i, i};
            }
            if (m[key][0] > freq ||
                (m[key][0] == freq &&
                 (m[key][2] - m[key][1]) < (m[mx][2] - m[mx][1]))) {
                freq = m[key][0];
                mx = key;
            }
        }
        return m[mx][2] - m[mx][1] + 1;
    }
};

int main() {
    Solution INSTANCE;
    vector<int> nums = {1, 2, 2, 3, 1};
    cout << INSTANCE.findShortestSubArray(nums);
    return 0;
}
