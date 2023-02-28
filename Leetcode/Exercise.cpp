#include "../QuikTemplate.cpp"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
  // L2
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *dummyNode = new ListNode(-1);
    ListNode *cur = dummyNode;
    int sum = 0;

    while (l1 != nullptr || l2 != nullptr || sum > 0) {
      sum += (l1 != nullptr ? l1->val : 0) + (l2 != nullptr ? l2->val : 0);
      cur->next = new ListNode(sum % 10);
      // update
      if (l1 != nullptr)
        l1 = l1->next;
      if (l2 != nullptr)
        l2 = l2->next;
      sum = sum / 10;
      cur = cur->next;
    }
    return dummyNode->next;
  }
  // L141
  bool hasCycle(ListNode *head) {
    if (head == nullptr)
      return false;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast)
        return true;
    }
    return false;
  }
  // L3
  int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int i = 0, j = 0, ans = 0;
    unordered_set<char> st;
    while (i < n && j < n) {
      if (!st.count(s[j])) {
        st.insert(s[j]);
        j++;
        ans = max(ans, j - i);
      } else {
        st.erase(s[i]);
        i++;
      }
    }
    return ans;
  }
  // L40
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> ans;
    sort(candidates.begin(), candidates.end());
    vector<int> cur;
    dfs(candidates, target, 0, ans, cur);
    return ans;
  }
  void dfs(vector<int> &candidates, int target, int s, vector<vector<int>> &ans, vector<int> &curr) {
    if (target == 0) {
      ans.push_back(curr);
      return;
    }
    for (int i = s; i < candidates.size(); i++) {
      if (i > s && candidates[i] == candidates[i - 1])
        continue; // skip dup element , ans 也可以用set代替 set<vector<int>> ans;
      int num = candidates[i];

      if (num > target)
        return;
      curr.push_back(num);
      dfs(candidates, target - num, i + 1, ans, curr);
      curr.pop_back();
    }
  }
  // L234
  bool isPalindrome(ListNode *head) {
    if (head == nullptr)
      return true;
    ListNode *cur = head;
    stack<int> s;
    while (cur != nullptr) {
      s.push(cur->val);
      cur = cur->next;
    }
    while (!s.empty()) {
      int val = s.top();
      s.pop();
      if (val != head->val)
        return false;
      else
        head = head->next;
    }
    return true;
  }
  // L5
  string longestPalindrome(string s) {
    if (s.size() <= 1)
      return s;
    int len = 0, start = 0, end = 0;
    for (int i = 0; i < s.size(); i++) {
      int len1 = expandAroundCenter(s, i, i);
      int len2 = expandAroundCenter(s, i, i + 1);
      int tempLen = max(len1, len2);
      if (tempLen > (end - start + 1)) {
        // 奇偶性 2 1 i 1 2
        //      i-2 i-1 i i+1 i+2
        //      len = 5
        //      2 1 i i 1 2
        //      i-2 i-1 i i+1 i+2 i+3
        //     len = 6
        //      update
        start = i - (tempLen - 1) / 2;
        end = i + tempLen / 2;
      }
    }
    return s.substr(start, end - start + 1);
  }
  int expandAroundCenter(string s, int lo, int hi) {
    while (lo >= 0 && hi < s.size() && s[lo] == s[hi]) {
      lo--;
      hi++;
    }
    return hi - lo - 1;
  }

  // L71
  string simplifyPath(string path) {
    deque<string> dq;
    int n = path.size();
    for (int i = 1; i < n; i++) {
      if (path[i] == '/')
        continue;
      int j = i + 1;
      while (j < n && path[j] != '/')
        j++;
      string dirName = path.substr(i, j - i);
      if (dirName == "..") {
        if (!dq.empty()) {
          dq.pop_back();
        }
      } else if (dirName != ".") {
        dq.push_back(dirName);
      }
      i = j;
    }
    string ans;
    while (!dq.empty()) {
      ans.append("/");
      ans.append(dq.front());
      dq.pop_front();
    }
    return ans.size() == 0 ? "/" : ans;
  }
  // L560
  int subarraySum(vector<int> &nums, int k) {
    int ans = 0, sum = 0;
    unordered_map<int, int> m;
    m[0] = 1;
    for (auto x : nums) {
      sum += x;
      int key = sum - k;
      if (m.count(key))
        ans += m[key];
      m[sum]++;
    }
    return ans;
  }
  // 2406
  int minGroups(vector<vector<int>> &arr) {
    sort(arr.begin(), arr.end(), [](const vector<int> &a, const vector<int> &b) -> bool { return a[0] < b[0]; });
    auto cmp = [](const int a, const int b) -> bool { return a > b; };
    priority_queue<int, vector<int>, decltype(cmp)> maxHeap(cmp);
    for (auto item : arr) {
      int l = item[0], r = item[1];
      if (maxHeap.empty() || maxHeap.top() >= l) {
        // 有交集 新开一组
        //   -----
        //      -------
        maxHeap.push(r);
      } else {
        // 无交集 更新下右端点
        // ----
        //      -----
        maxHeap.pop();
        maxHeap.push(r);
      }
    }
    return maxHeap.size();
  }

  // L435
  // https://www.acwing.com/problem/content/description/910/ ac908
  int eraseOverlapIntervals(vector<vector<int>> &arr) {
    sort(arr.begin(), arr.end(), [](vector<int> &a, vector<int> &b) -> bool { return a[1] < b[1]; });
    int n = arr.size();
    int ans = 0;
    int end = -INF;
    for (int i = 0; i < n; i++) {
      if (arr[i][0] >= end) {
        ans++;
        end = arr[i][1];
      }
    }
    return n - ans;
  }
  // 1024
  // 加上success 是因为要覆盖corner case 比如 [1,3] [3,5] 这种啦
  int videoStitching(vector<vector<int>> &clips, int time) { return videoStitching_(clips, 0, time); }
  int videoStitching_(vector<vector<int>> &clips, int s, int e) {
    sort(clips.begin(), clips.end());
    // 区间左短点 从小到大排序
    // 枚举 在所有能覆盖start区间内内选择右端点最大的区间
    int res = 0;
    int n = clips.size();
    bool success = false;
    for (int i = 0; i < n; i++) {
      int j = i, r = -0x3F3F3F3F;
      while (j < n && clips[j][0] <= s) {
        r = max(r, clips[j][1]);
        j++;
      }
      if (r < s) {
        res = -1;
        break;
      }
      res++;
      if (r >= e) {
        success = true;
        break;
      }
      s = r;
      i = j - 1;
    }
    if (!success)
      res = -1;
    return res;
  }
};