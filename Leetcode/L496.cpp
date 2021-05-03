#include <iostream>
#include <map>
#include <stack>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> s;
        map<int, int> m;
        for (int i = 0; i < nums2.size(); i++) {
            while (!s.empty() && s.top() < nums2[i]) {
                m[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        for (int i = 0; i < nums1.size(); i++) {
            ans.emplace_back(m.count(nums1[i]) ? m[nums1[i]] : -1);
        }
        return ans;
    }
};
