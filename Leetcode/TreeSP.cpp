#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <stack>
#include <cmath>

using namespace std;

const int MAX_VALUE = 0x7FFFFFFF, MIN_VALUE = 0x80000000, INF = 0x3F3F3F3F, MOD = 1E9 + 7;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
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
    // 104
    int maxDepth(TreeNode *root) {
        if (root == NULL) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

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

private:
    vector<int> ans;
public:
    vector<int> inorderTraversal(TreeNode *root) {
        if (root == nullptr) return ans;
        help(root);
        return ans;
    }

    void help(TreeNode *root) {
        if (root == nullptr) return;
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
        if (l > r) return nullptr;
        int mid = (r - l) / 2 + l;
        TreeNode *root = new TreeNode(arr[mid]);
        root->left = buildBSTree(arr, l, mid - 1);
        root->right = buildBSTree(arr, mid + 1, r);
        return root;
    }
};

