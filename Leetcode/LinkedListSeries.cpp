#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
const int MAX_VALUE = 0x7FFFFFFF, MIN_VALUE = 0x80000000, INF = 0x3F3F3F3F, kMod = 1E9 + 7;
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
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

struct ListNode {
  int val;
  ListNode *next;

  ListNode() : val(0), next(nullptr) {}

  ListNode(int x) : val(x), next(nullptr) {}

  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  // // L2
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *p = l1;
    ListNode *q = l2;
    int carry = 0;
    ListNode *dummyNode = new ListNode();
    ListNode *cur = dummyNode;
    while (p != nullptr || q != nullptr) {
      int sum = (p == nullptr ? 0 : p->val) + (q == nullptr ? 0 : q->val) + carry;
      cur->next = new ListNode(sum % 10);
      cur = cur->next;
      carry = sum / 10;
      if (p != nullptr) {
        p = p->next;
      }
      if (q != nullptr) {
        q = q->next;
      }
    }
    if (carry != 0) {
      cur->next = new ListNode(carry);
    }
    return dummyNode->next;
  }

  // 83
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *cur = head;
    while (cur != nullptr && cur->next != nullptr) {
      if (cur->val == cur->next->val) {
        cur->next = cur->next->next;
      } else {
        cur = cur->next;
      }
    }
    return head;
  }

  // 82
  ListNode *deleteDuplicates_(ListNode *head) {
    ListNode *dummyNode = new ListNode();
    dummyNode->next = head;
    ListNode *cur = dummyNode;
    while (cur->next != nullptr && cur->next->next != nullptr) {
      if (cur->next->val == cur->next->next->val) {
        int x = cur->next->val;
        while (cur->next != nullptr && cur->next->val == x) {
          cur->next = cur->next->next;
        }
      } else {
        cur = cur->next;
      }
    }
    return dummyNode->next;
  }

  // L86
  ListNode *partition(ListNode *head, int x) {
    ListNode *large = new ListNode();
    ListNode *largeHead = large;
    ListNode *small = new ListNode();
    ListNode *smallHead = small;
    while (head != nullptr) {
      if (head->val < x) {
        small->next = head;
        small = small->next;
      } else {
        large->next = head;
        large = large->next;
      }
      head = head->next;
    }
    large->next = nullptr;
    small->next = largeHead->next;
    return smallHead->next;
  }

  // L445
  ListNode *addTwoNumbersⅡ(ListNode *l1, ListNode *l2) {
    ListNode *a = reverseListNode(l1);
    ListNode *b = reverseListNode(l2);
    ListNode *ans = addTwoNumbers(a, b);
    return reverseListNode(ans);
  }

  ListNode *reverseListNode(ListNode *head) {
    ListNode *prev = nullptr;
    while (head != nullptr) {
      ListNode *nxt = head->next;
      head->next = prev;
      prev = head;
      head = nxt;
    }
    return prev;
  }

  // L725
  vector<ListNode *> splitListToParts(ListNode *root, int k) {
    ListNode *cur = root;
    int N = 0;
    while (cur != nullptr) {
      cur = cur->next;
      N++;
    }
    int width = N / k, rem = N % k;
    vector<ListNode *> ans(k);
    cur = root;
    for (int i = 0; i < k; ++i) {
      ListNode *head = cur;
      for (int j = 0; j < (width + (i < rem ? 1 : 0) - 1); ++j) { // 是 i < rem ? 1:0 不是 j<rem哦
        if (cur != nullptr)
          cur = cur->next;
      }
      if (cur != nullptr) {
        ListNode *prev = cur;
        cur = cur->next;
        prev->next = nullptr;
      }
      ans[i] = head;
    }
    return ans;
  }

  // 817
  int numComponents(ListNode *head, vector<int> &nums) {
    vector<bool> exists(10001, false);
    for (auto x : nums) {
      exists[x] = true;
    }
    int cnt = 0;
    while (head != nullptr) {
      if (exists[head->val] && (head->next == nullptr || !exists[head->next->val])) {
        cnt++;
      }
      head = head->next;
    }
    return cnt;
  }
  // 430
  Node *flatten(Node *head) {
    dfs(head);
    return head;
  }

  // 返回尾节点
  Node *dfs(Node *h) {
    if (h == nullptr)
      return nullptr;
    Node *child = h->child;
    Node *nxt = h->next;
    h->child = nullptr;
    if (child && nxt) {
      Node *childEnd = dfs(child);
      Node *nextEnd = dfs(nxt);

      h->next = child;
      child->prev = h;

      childEnd->next = nxt;
      nxt->prev = childEnd;

      return nextEnd;
    } else if (!child && nxt) {
      Node *nextEnd = dfs(nxt);
      return nextEnd;
    } else if (child && !nxt) {
      Node *childEnd = dfs(child);
      h->next = child;
      child->prev = h;
      return childEnd;
    } else {
      return h;
    }
  }

  // 1019
  vector<int> nextLargerNodes(ListNode *head) {
    stack<pii> s;
    vector<int> ans;
    int idx = 0;
    while (head != nullptr) {
      while (!s.empty() && s.top().first < head->val) {
        ans[s.top().second] = head->val;
        s.pop();
      }
      s.push({head->val, idx});
      ans.push_back(0);
      head = head->next;
      idx++;
    }
    return ans;
  }

  // 1699
  ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {

    ListNode *prev = list1;
    ListNode *slow = list1;
    ListNode *fast = list1;
    for (int i = 0; i < b - a; i++) {
      fast = fast->next;
    }
    for (int i = 0; i < a; i++) {
      prev = slow;
      slow = slow->next;
      fast = fast->next;
    }

    ListNode *cur = list2;
    while (cur->next != nullptr) {
      cur = cur->next;
    }
    prev->next = list2;
    cur->next = fast->next;
    return list1;
  }

  // 1721
  ListNode *swapNodes(ListNode *head, int k) {

    ListNode *slow = head;
    ListNode *fast = head;
    for (int i = 0; i < k - 1; i++) {
      fast = fast->next;
    }
    ListNode *s1 = fast;

    while (fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next;
    }
    ListNode *s2 = slow;

    int tmp = s1->val;
    s1->val = s2->val;
    s2->val = tmp;
    return head;
  }

  // 1367
  bool isSubPath_(ListNode *head, TreeNode *root) { // 错误做法
    if (head == nullptr)
      return true;
    if (root == nullptr)
      return false;
    // https://leetcode-cn.com/problems/linked-list-in-binary-tree/comments/484462
    // 如果满足相等条件,就会一直从根节点往下走, 无法退回到左右子树为根节点开始寻找
    if (root->val == head->val) {
      return isSubPath(head->next, root->left) || isSubPath(head->next, root->right);
    } else {
      return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
  }
  // 1367
  bool isSubPath(ListNode *head, TreeNode *root) {
    if (root == nullptr)
      return false;
    return isSubPathFromRoot(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
  }

  bool isSubPathFromRoot(ListNode *head, TreeNode *root) {
    if (head == nullptr)
      return true;
    if (root == nullptr) // 后判断,先判断head是否为null
      return false;
    if (root->val != head->val)
      return false;
    return isSubPathFromRoot(head->next, root->left) || isSubPathFromRoot(head->next, root->right);
  }

  // 1171
  ListNode *removeZeroSumSublists(ListNode *head) {
    ListNode *dummyNode = new ListNode(); // 为什么要加上dummyNode是因为可能返回空集合
    dummyNode->next = head;
    unordered_map<int, ListNode *> m;
    int sum = 0;
    ListNode *cur = dummyNode;
    while (cur != nullptr) {
      sum += cur->val;
      m[sum] = cur;
      cur = cur->next;
    }
    // reset
    sum = 0;
    cur = dummyNode;
    while (cur != nullptr) {
      sum += cur->val;
      cur->next = m[sum]->next; // 覆盖了
      cur = cur->next;
    }
    return dummyNode->next;
  }

  // 2058
  vector<int> nodesBetweenCriticalPoints(ListNode *head) {
    int maxD = -1, minD = -1;
    int first = -1, pos = 0, last = -1;
    ListNode *cur = head;
    while (cur->next->next) {
      int x = cur->val;
      int y = cur->next->val;
      int z = cur->next->next->val;
      if (y > max(x, z) || y < min(x, z)) {
        if (last != -1) {
          minD = minD == -1 ? pos - last : min(minD, pos - last); // 因为是min 所以要用三元运算符算下
          maxD = max(maxD, pos - first);
        }
        if (first == -1) {
          first = pos;
        }
        last = pos;
      }
      cur = cur->next;
      pos++;
    }
    return {minD, maxD};
  }

  ListNode *partition(ListNode *head, int x) {}
};