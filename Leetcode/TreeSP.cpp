#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

const int MAX_VALUE = 0x7FFFFFFF, MIN_VALUE = 0x80000000, INF = 0x3F3F3F3F, MOD = 1E9 + 7;
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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  // 94
  vector<int> inorderTraversal_v1(TreeNode *root) {
    stack<TreeNode *> s;
    vector<int> ans;
    TreeNode *cur = root;
    while (!s.empty() || cur != nullptr) {
      if (cur != NULL) {
        s.push(cur);
        cur = cur->left;
      } else {
        cur = s.top();
        s.pop();
        ans.EB(cur->val);
        cur = cur->right;
      }
    }
    return ans;
  }

  // 99 2种解法 一种递归 一种非递归
  // dfs 版本
  TreeNode *prev = new TreeNode(MIN_VALUE);
  TreeNode *first;
  TreeNode *second;
  void recoverTree(TreeNode *root) {
    dfsRecover(root);
    int tmp = first->val;
    first->val = second->val;
    second->val = tmp;
  }

  void dfsRecover(TreeNode *root) {
    if (!root)
      return;
    dfsRecover(root->left);
    if (root->val >= prev->val) {
      prev = root;
    } else {
      if (!first) {
        first = prev;
        prev = root;
        second = root; // 二次更新 被覆盖
      } else {
        second = root;
        return;
      }
    }
    dfsRecover(root->right);
  }
  // 99  非递归版本
  void recoverTree(TreeNode *root) {
    stack<TreeNode *> s;
    TreeNode *cur = root;
    while (!s.empty() || cur != nullptr) {
      if (cur) {
        s.push(cur);
        cur = cur->left;
      } else {
        cur = s.top();
        s.pop();
        if (cur->val >= prev->val) {
          prev = cur;
        } else {
          if (!first) {
            first = prev;
            prev = cur;
            second = cur; // 二次更新 被覆盖
          } else {
            second = cur;
            break; // 不是return 是break 别搞错了!
          }
        }
        cur = cur->right;
      }
    }
    // swap
    int tmp = first->val;
    first->val = second->val;
    second->val = tmp;
  }

  // 104
  int maxDepth(TreeNode *root) {
    if (root == NULL)
      return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }
  // 107
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    queue<TreeNode *> q;
    vector<vector<int>> ans;
    if (!root)
      return ans;
    q.push(root);
    while (!q.empty()) {
      int len = q.size();
      vector<int> data;
      while (len--) {
        TreeNode *node = q.front();
        q.pop();
        data.PB(node->val);
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      ans.PB(data);
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }

  // 114 递归
  void flatten(TreeNode *root) {
    if (!root)
      return;
    flatten(root->left);
    flatten(root->right);
    TreeNode *tmp = root->right;
    root->right = root->left;
    root->left = nullptr;
    // 将root左子树最远右端点指向root的右节点
    while (root->right) {
      root = root->right;
    }
    root->right = tmp;
  }
  // 114 非递归版本
  void flatten(TreeNode *root) {
    if (!root)
      return;
    TreeNode *cur = root;
    while (cur) {
      if (cur.left) {
        TreeNode *p = cur->left;
        while (p->right)
          p = p->right;
        p->right = cur->right;
        cur->right = cur->left;
        cur->left = null;
      }
      cur = cur.right;
    }
  }

  // 129 DFS即可 BFS也行
  int sumNumbers(TreeNode *root) { return dfs(root, 0); }
  int dfs(TreeNode *root, int prev) {
    if (!root)
      return 0;
    int sum = prev * 10 + root->val;
    if (!root->left && !root->right) {
      return sum;
    } else {
      return dfs(root->left, sum) + dfs(root->right, sum);
    }
  }

private:
  vector<int> ans;

public:
  vector<int> inorderTraversal(TreeNode *root) {
    if (root == nullptr)
      return ans;
    help(root);
    return ans;
  }

  void help(TreeNode *root) {
    if (root == nullptr)
      return;
    help(root->left);
    ans.EB(root->val);
    help(root->right);
  }

  // 1382
  TreeNode *balanceBST(TreeNode *root) {
    help(root);
    return buildBSTree(ans, 0, ans.size() - 1);
  }

  TreeNode *buildBSTree(vector<int> arr, int l, int r) {
    if (l > r)
      return nullptr;
    int mid = (r - l) / 2 + l;
    TreeNode *root = new TreeNode(arr[mid]);
    root->left = buildBSTree(arr, l, mid - 1);
    root->right = buildBSTree(arr, mid + 1, r);
    return root;
  }

  // 513
  int findBottomLeftValue(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    int ans;
    while (!q.empty()) {
      int len = q.size();
      ans = q.front()->val;
      while (len--) {
        TreeNode *node = q.front();
        q.pop();
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
    }
    return ans;
  }
  // 669
  TreeNode *trimBST(TreeNode *root, int low, int high) {}
  // 1305
  vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
    vector<int> d1, d2;
    dfs(root1, d1);
    dfs(root2, d2);
    int i = 0, j = 0;
    int n = d1.size(), m = d2.size();
    vector<int> ans;
    while (i < n && j < m) {
      /* if (d1[i] < d2[j]) {
         ans.push_back(d1[i++]);
       } else {
         ans.push_back(d2[j++]);
       }*/
      if (i < n && (j == m || d1[i] <= d2[j])) {
        ans.push_back(d1[i++]);
      } else {
        ans.push_back(d2[j++]);
      }
    }
    while (i < n) {
      ans.push_back(d1[i++]);
    }
    while (j < m) {
      ans.push_back(d2[j++]);
    }
    return ans;
  }
  void dfs(TreeNode *root, vector<int> &data) {
    if (!root)
      return;
    dfs(root->left, data);
    data.push_back(root->val);
    dfs(root->right, data);
  }

  // 951
  bool flipEquiv(TreeNode *root1, TreeNode *root2) {
    if (!root1 && !root2)
      return true;
    if (!root1 || !root2 || root1->val != root2->val)
      return false;
    else
      return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
             (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
  }

  // 1315
  int ans1315 = 0;
  int sumEvenGrandparent_(TreeNode *root) {
    if (!root->left) {
      dfs(root, root->left, root->left->left);
      dfs(root, root->left, root->left->right);
    }
    if (!root->right) {
      dfs(root, root->right, root->right->left);
      dfs(root, root->right, root->right->right);
    }
    dfs(nullptr, nullptr, root)
  }

  void dfs(TreeNode *g, TreeNode *p, TreeNode *n) {
    if (!n)
      return;
    if (g->val % 2 == 0) {
      ans1315 += node->val;
    }
    dfs(p, n, n->left);
    dfs(p, n, n->right);
  }

  // 1315
  int sumEvenGrandparent(TreeNode *root) {
    dfs(1, 1, root);
    return ans1315;
  }

  void dfs(int gVal, int pVal, TreeNode *n) {
    if (!n)
      return;
    if (gVal % 2 == 0) {
      ans1315 += n->val;
    }
    dfs(pVal, n->val, n->left);
    dfs(pVal, n->val, n->right);
  }

  // 1609
  bool isEvenOddTree(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    int level = 0;
    while (!q.empty()) {
      int len = q.size();
      int prev = level % 2 == 0 ? -INF : INF;
      for (int i = 0; i < len; i++) {
        TreeNode *node = q.front();
        q.pop();
        // 条件是层次缺一不可的关系 没有或
        if (!((level % 2 == 0 && node->val % 2 == 1 && node->val > prev) ||
              (level % 2 == 1 && node->val % 2 == 0 && node->val < prev)))
          return false;
        prev = node->val;
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      level++;
    }
    return true;
  }

  // 894 ❤️
  unordered_map<int, vector<TreeNode *>> memo;
  vector<TreeNode *> allPossibleFBT(int N) {
    if (memo.find(N) == memo.end()) {
      vector<TreeNode *> ans;
      if (N == 1) {
        ans.PB(new TreeNode(0));
      } else if (N % 2 == 1) {
        for (int l = 0; l < N; l++) {
          int r = N - 1 - l;
          for (TreeNode *left : allPossibleFBT(l)) {
            for (TreeNode *right : allPossibleFBT(r)) {
              ans.PB(new TreeNode(0, left, right));
            }
          }
        }
      }
      memo[N] = ans;
    }
    return memo[N];
  }

  // 669
  TreeNode *trimBST(TreeNode *root, int low, int high) {
    if (!root)
      return nullptr;
    if (root->val < low)
      return trimBST(root->right, low, high);
    if (root->val > high)
      return trimBST(root->left, low, high);
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
  }
  // 652 https://youtu.be/JLK92dbTt8k  https://youtu.be/YupKiFqtnsA
  unordered_map<string, int> key2Id;
  unordered_map<string, int> key2count;
  vector<TreeNode *> ans;
  vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
    getId(root);
    return ans;
  }
  int cnt = 0;
  // 为什么需要序列化 是因为需要在遍历前后 非中间 进行记忆化操作 ,否则 O(N²)的时间复杂度了
  int getId(TreeNode *root) {
    if (!root)
      return -1; // 和 cnt 不能一样哦  不然 一个值 代表2种心态
    string key = to_string(root->val) + "#" + to_string(getId(root->left)) + "#" + to_string(getId(root->right));
    if (key2Id.find(key) == key2Id.end()) {
      key2Id[key] = cnt++;
      key2count[key] = 1;
    } else {
      key2count[key] += 1;
      if (key2count[key] == 2) {
        ans.push_back(root);
      }
    }
    return key2Id[key];
  }
  // 654
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    if (!nums.size())
      return nullptr;
    auto mx = max_element(nums.begin(), nums.end());
    TreeNode *root = new TreeNode(*mx);
    vector<int> left(nums.begin(), mx);
    vector<int> right(mx + 1, nums.end());
    root->left = constructMaximumBinaryTree(left);
    root->right = constructMaximumBinaryTree(right);
    return root;
  }

  // 222
  int countNodes(TreeNode *root) {
    if (!root)
      return 0;
    int l = level(root->left);
    int r = level(root->right);
    // 要理解 左右对半开, 必定 存在至少 一个(要么是左子树 要么是右子树是满二叉树 暨叶子结点完全填满 !)
    if (l == r) {
      return (1 << l) + countNodes(root->right);
    } else {
      return (1 << r) + countNodes(root->left);
    }
  }
  int level(TreeNode *root) {
    int level = 0;
    while (root) {
      root = root->left;
      level++;
    }
    return level;
  }

  // 二分查找 版本;

  // 998
  TreeNode *insertIntoMaxTree(TreeNode *root, int val) {
    TreeNode *node = new TreeNode(val);
    if (!root || root->val < val) {
      node->left = root;
      return node;
    }
    TreeNode *pre;
    TreeNode *ans = root;
    while (root && root->val > val) {
      pre = root;
      root = root->right;
    }
    pre->right = node;
    if (root) {
      node->left = root; // 改成node->right = root 为什么就错了呢
    }
    return ans;
  }

  // 1372
  int longestZigZag(TreeNode *root) {}

  // 958
  bool isCompleteTree(TreeNode *root) {
    if (!root)
      return true;
    queue<TreeNode *> q;
    q.push(root);
    bool missing = false;
    while (!q.empty()) {
      int len = q.size();
      while (len--) {
        TreeNode *node = q.front();
        q.pop();
        if (node) {
          if (missing)
            return false;
          q.push(node->left);
          q.push(node->right);
        } else {
          missing = true;
        }
      }
    }
    return true;
  }

  // 1080
  TreeNode *sufficientSubset(TreeNode *root, int limit) {
    bool needDel = dfs(root, 0, limit);
    if (needDel)
      return nullptr;
    else
      return root;
  }

  bool dfs(TreeNode *root, int sum, int limit) {
    if (!root)
      return true;
    if (!root->left && !root->right) {
      return root->val + sum < limit;
    }
    bool rDel = true;
    bool lDel = true;
    if (root->left) {
      lDel = dfs(root->left, root->val + sum, limit);
    }
    if (root->right) {
      rDel = dfs(root->right, root->val + sum, limit);
    }
    if (lDel) {
      root->left = nullptr;
    }
    if (rDel) {
      root->right = nullptr;
    }
    return lDel && rDel;
  }

  // 988
  string ans = "z";
  string smallestFromLeaf(TreeNode *root) {
    if (!root)
      return ans;
    dfsSmallest(root, "");
    return ans;
  }
  // 传的是string value copy. 不需要进行回溯删除
  void dfsSmallest(TreeNode *root, string s) {
    if (!root)
      return;
    s += (char)(root->val + 'a');
    if (!root->left && !root->right) {
      reverse(s.begin(), s.end());
      ans = min(ans, s);
      return;
    }
    if (root->left)
      dfsSmallest(root->left, s);
    if (root->right)
      dfsSmallest(root->right, s);
  }
  // 1339
  int sum = 0;
  int maxProduct(TreeNode *root) {
    dfs(root);
    dfs2(root);
    return (long long)best * (sum - best) % 1000000007;
  }
  void dfs(TreeNode *root) {
    if (!root)
      return;
    sum += root->val;
    dfs(root->left);
    dfs(root->right);
  }
  int best = 0;
  int dfs2(TreeNode *root) {
    if (!root)
      return 0;
    int cur = root->val + dfs2(root->left) + dfs2(root->right);
    if (abs(2 * cur - sum) < abs(2 * best - sum)) {
      best = cur;
    }
    return cur;
  }
  // 面试题 04.03. 特定深度节点链表 https://leetcode-cn.com/problems/list-of-depth-lcci/
  vector<ListNode *> listOfDepth(TreeNode *tree) {}

  // LCP 34. 二叉树染色  https://leetcode-cn.com/problems/er-cha-shu-ran-se-UGC/
  int maxValue(TreeNode *root, int k) {}

  // 1104
  vector<int> pathInZigZagTree(int label) {}

  // 508
  unordered_map<int, int> m;
  int mx = -1;
  vector<int> findFrequentTreeSum(TreeNode *root) {
    dfs(root);
    vector<int> ans;
    for (auto item : m) {
      if (item.second == mx)
        ans.push_back(item.first);
    }
    return ans;
  }
  int dfs(TreeNode *root) {
    if (!root)
      return 0;
    int l = dfs(root->left);
    int r = dfs(root->right);
    int sum = root->val + l + r;
    m[sum]++;
    mx = max(mx, m[sum]);
    return sum;
  }
};
