#include <iostream>
#include <map>
#include <stack>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len = nums.size();
        stack<int> s;
        vector<int> ans(len, -1);
        for (int i = 0; i < 2 * len; i++) {
            while (!s.empty() && nums[s.top()] < nums[i % len]) {
                ans[s.top()] = nums[i % len];
                s.pop();
            }
            s.push(i % len);
        }
        return ans;
    }
};

int main() { return 0; }