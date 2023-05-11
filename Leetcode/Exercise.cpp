#include "../QuikTemplate.cpp"

using namespace std;
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

  // L207   topology sort+dfs
  // status 0 unvisited 1 visiting 2 visited
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> G(numCourses);
    for (const auto &item : prerequisites)
      G[item[0]].push_back(item[1]);

    vector<int> v(numCourses, 0);
    vector<int> ans;
    for (int i = 0; i < numCourses; ++i)
      if (hasCycle(G, i, v, ans))
        return false;
    return true;
  }

  // 要写成指针类型, 因为是递归 不要传值  传引用啦
  bool hasCycle(vector<vector<int>> &G, int cur, vector<int> &v, vector<int> &ans) {
    if (v[cur] == 1)
      return true;
    if (v[cur] == 2)
      return false;

    v[cur] = 1;
    for (const int t : G[cur])
      if (hasCycle(G, t, v, ans))
        return true;
    v[cur] = 2;

    ans.push_back(cur);
    return false;
  }

  // L207 topology sort + BFS 210等同
  bool canFinish_(int numCourses, vector<vector<int>> &prerequisites) {
    if (numCourses < 0)
      return false;
    if (prerequisites.size() == 0)
      return true;
    unordered_map<int, int> indegree;
    unordered_map<int, set<int>> outDegree;
    for (vector<int> item : prerequisites) {
      int v = item[0], u = item[1];
      indegree[v]++;
      outDegree[u].insert(v);
    }

    vector<int> q;
    for (int i = 0; i < numCourses; i++) {
      if (indegree[i] == 0) {
        q.push_back(i);
      }
    }
    vector<int> ans;
    while (!q.empty()) {
      int zeroV = q.back();
      ans.push_back(zeroV);
      q.pop_back();
      for (const auto &v : outDegree[zeroV]) {
        indegree[v]--;
        if (indegree[v] == 0) {
          q.push_back(v);
        }
      }
    }
    return ans.size() == numCourses;
  }

  // L215
  int findKthLargest(vector<int> nums, int k) {
    int left = 0, right = nums.size() - 1;
    while (true) {
      int pos = partition(nums, left, right);
      if (pos == nums.size() - k)
        return nums[pos];
      if (pos < nums.size() - k) {
        left = pos + 1;
      } else {
        right = pos - 1;
      }
    }
  }

  int partition(vector<int> &nums, int l, int r) {
    int j = rand() % (r - l) + l;
    swap(nums[j], nums[l]);
    int pivotIdx = l;
    int index = l + 1;
    // 从左至右遍历
    for (int i = index; i <= r; i++) {
      if (nums[i] < nums[pivotIdx]) {
        swap(nums[i], nums[index]);
        index++;
      }
    }
    swap(nums[pivotIdx], nums[index - 1]);
    return index - 1;
  }
  // L283
  void moveZeroes(vector<int> &nums) {
    int swapIdx = 0; // 1 2 0 3 4
                     // 1 2 3 0 4
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != 0) {
        swap(nums[swapIdx], nums[i]);
        swapIdx++;
      }
    }
  }

  // L148
  ListNode *sortList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode *slow = head, *fast = head;
    ListNode *prev = head;
    while (fast != nullptr && fast->next != nullptr) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    // break
    prev->next = nullptr;
    ListNode *l1 = sortList(head);
    ListNode *l2 = sortList(slow);
    return mergeTwoLists(l1, l2);
  }

  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *dummyNode = new ListNode(-1);
    ListNode *cur = dummyNode;
    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val < l2->val) {
        cur->next = new ListNode(l1->val);
        l1 = l1->next;
      } else {
        cur->next = new ListNode(l2->val);
        l2 = l2->next;
      }
      cur = cur->next;
    }
    if (l1 == nullptr) {
      cur->next = l2;
    } else if (l2 == nullptr) {
      cur->next = l1;
    }
    return dummyNode->next;
  }

  // L23
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.size() < 1) {
      return nullptr;
    }
    return mergeKLists(lists, 0, lists.size() - 1);
  }

  ListNode *mergeKLists(vector<ListNode *> &lists, int start, int end) {
    if (start == end) {
      return lists[start];
    }
    int mid = (end - start) / 2 + start;
    ListNode *l1 = mergeKLists(lists, start, mid);
    ListNode *l2 = mergeKLists(lists, mid + 1, end);
    return mergeTwoLists(l1, l2);
  }

  // 31. 下一个排列 首先理解字典序   找下一个字典序更大的 如果最大了 就全局升序排列了
  //  题解连接 https://youtu.be/1ja5s9TmwZM  1274311
  void nextPermutation(vector<int> &nums) {
    int i = nums.size() - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
      i--;
    }
    // 找到第一个破坏 descend order -->i  // 123 9860
    if (i >= 0) {
      int j = nums.size() - 1;
      while (j >= 0 && nums[j] <= nums[i]) {
        j--;                  // step1: 从右往左找第一个大于i的值 并且swap // 123 98 60
      }
      swap(nums[i], nums[j]); //  // 126 98 30
    }
    // step2: 然后 逆序 [i+1,len-1]区间
    reverse(nums.begin() + i + 1, nums.end()); // 126 0389
  }

  //  239  返回沿数组 固定K窗口长度滑动的最大值
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    multiset<int> set;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
      set.insert(nums[i]);
      if (set.size() > k) {
        set.erase(set.lower_bound(nums[i - k]));
      }
      if (set.size() >= k) {
        ans.push_back(*set.rbegin());
      }
    }
    return ans;
  }
  vector<int> maxSlidingWindow_(vector<int> &nums, int k) {
    vector<int> ans;
    deque<int> q;
    for (int i = 0; i < nums.size(); i++) {
      // 正常长度了
      while (!q.empty() && (i - q.front()) >= k)
        q.pop_front(); // (i-q.front())>=k 表示当前的队列元素已经是K个了, 第i个元素想要加入, 自然就把最前面的那个Pop
      while (!q.empty() &&
             nums[q.back()] < nums[i]) { // 新来的比尾部的大, 那么就把尾部的踢出去, 因为要维持单调递减队列啊
        q.pop_back();
      }
      q.push_back(i);       // 正常迭代添加
      if (i - k + 1 >= 0) { // 当前元素超过 K长度了
        ans.push_back(nums[q.front()]);
      }
    }
    return ans;
  }
  // 300 https://www.youtube.com/watch?v=Q6KyDl_xiIg
  int lengthOfLIS(vector<int> &nums) {
    vector<int> ans;
    for (auto ele : nums) {
      auto pos = ::lower_bound(ans.begin(), ans.end(), ele);
      if (pos == ans.end()) {
        ans.push_back(ele);
      } else {
        *pos = ele;
      }
    }
    return ans.size();
  }
  // 673
  int findNumberOfLIS(vector<int> &nums) {
    int N = nums.size();
    vector<int> len(N, 1);
    vector<int> num(N, 1);
    for (int i = 1; i < N; i++) {
      int maxLen = 1;
      int maxNum = 1;
      for (int j = 0; j < i; j++) {
        if (nums[i] <= nums[j]) {
          continue;
        }
        if (len[j] + 1 > maxLen) {
          maxLen = len[j] + 1;
          maxNum = num[j];
        } else if (len[j] + 1 == maxLen) {
          maxNum += num[j];
        }
      }
      len[i] = maxLen;
      num[i] = maxNum;
    }

    int maxLen = 1;
    int maxNum = 0;
    for (int i = 0; i < N; i++) {
      if (len[i] > maxLen) {
        maxLen = len[i];
        maxNum = num[i];
      } else if (len[i] == maxLen) {
        maxNum += num[i];
      }
    }
    return maxNum;
  }
};