
#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include <stack>

using namespace std;

const int INF = 0x3F3F3F3F;
const int MOD = 1E9 + 7;
#define ready ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
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
    TreeNode *lcaDeepestLeaves(TreeNode *root) {
        if (root == NULL) return NULL;
        int left = dfs(root->left);
        int right = dfs(root->right);
        if (left == right) return root;
        else if (left > right) return lcaDeepestLeaves(root->left);
        else return lcaDeepestLeaves(root->right);

    }

    int dfs(TreeNode *root) {
        if (root == NULL) return 0;
        else return 1 + max(dfs(root->left), dfs(root->right));
    }

    typedef pair<int, TreeNode *> Tr;

    Tr leavesDFS(TreeNode *root) {
        if (root == NULL) {
            return Tr(0, NULL);
        }
        auto l = leavesDFS(root->left);
        auto r = leavesDFS(root->right);
        if (l.first == r.first) {
            return Tr(l.first + 1, root);
        } else if (l.first > r.first) {
            return Tr(l.first + 1, l.second);
        } else {
            return Tr(r.first + 1, r.second);
        }
    }

    TreeNode *lcaDeepestLeaves_(TreeNode *root) {
        return leavesDFS(root).second;
    }

};