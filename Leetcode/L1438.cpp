#include <deque>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
   public:
    int longestSubarray_01(vector<int>& nums, int limit) {
        multiset<int> s;
        int n = nums.size();
        int l = 0, r = 0, ans = 0;
        while (r < n) {
            s.insert(nums[r]);
            // 为什么不能用end()
            // rbegin 和 end 区别
            //
            //在使用C++的STL时，经常会用到迭代器，那么不得不搞清楚里面的一些指针 begin(), end(), rbegin(), rend()之间的区别与联系，
            // 以及它们分别都指向哪个元素。首先要明白的一点是它们都是指针，
            // 其中begin()指向第一个元素，我们容易误认为end()是指向最后一个元素，其实不是的，
            // end()是指向最后一个元素的下一个。这就是为什么我们在使用map或是unordered_map来查找某个值时都要和end()比较呢，
            // 因为如果等于end()了，则说明所有的元素都遍历过一遍了，也包括最后一个元素。
            // rbegin()指向最后一个元素，rend()指向第一个元素，和begin()相等。
            while (*s.rbegin() - *s.begin() > limit) {
                s.erase(s.find(nums[l++]));
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
   public:
    // 前面我们只想知道滑动窗口最大值和最小值,所以可以用2个单调队列维护最值
    int longestSubarray_02(vector<int>& nums, int limit) {
        deque<int> minQ, maxQ;
        int l = 0, r = 0, ans = 0, n = nums.size();
        while (r < n) {
            while (!minQ.empty() && minQ.back() > nums[r]) minQ.pop_back();
            while (!maxQ.empty() && maxQ.back() < nums[r]) maxQ.pop_back();
            minQ.push_back(nums[r]);
            maxQ.push_back(nums[r]);
            while (!minQ.empty() && !maxQ.empty() &&
                   maxQ.front() - minQ.front() > limit) {
                if (nums[l] == minQ.front()) minQ.pop_front();
                if (nums[l] == maxQ.front()) maxQ.pop_front();
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};

int main() {}