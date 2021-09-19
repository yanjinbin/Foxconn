#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;
const int MAX_VALUE = 0x7FFFFFFF, MIN_VALUE = 0x80000000, INF = 0x3F3F3F3F, kMod = 1E9 + 7;
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

class SegTreeNode {
public:
    SegTreeNode *left;
    SegTreeNode *right;
    int start, end;
    int info;

    SegTreeNode(int l, int r) : start(l), end(r), info(0), left(NULL), right(NULL) {}
};

class SegTree {
public:
    vector<int> nums;
    SegTreeNode *root;
public:
    void updateSingle(SegTreeNode *node, int id, int val) {
        if (id < node->start || id > node->end) return;
        if (node->start == node->end) {
            node->info = val;
            return;
        }
        updateSingle(node->left, id, val);
        updateSingle(node->right, id, val);
        node->info = node->left->info + node->right->info;  // write your own logic
    }

    int queryRange(SegTreeNode *node, int l, int r) {
        if (r < node->start || l > node->end) {
            return 0;  // write your own logic
        }
        if (l <= node->start && r >= node->end) {
            return node->info;  // write your own logic
        }
        return queryRange(node->left, l, r) + queryRange(node->right, l, r);  // write your own logic
    };

    void init(SegTreeNode *node, int l, int r)  // init for range [a,b]
    {
        if (l == r) {
            node->info = nums[l];
            return;
        }
        int mid = (r - l) / 2 + l;
        if (node->left == NULL) {
            node->left = new SegTreeNode(l, mid);
            node->right = new SegTreeNode(mid + 1, r);
        }
        init(node->left, l, mid);
        init(node->right, mid + 1, r);
        node->info = node->left->info + node->right->info;  // write your own logic
    }
};


// https://bit.ly/3ww9h7D
class Solution {
public:
    SegTree *tree;
    vector<LL> vals;

    int countRangeSum(vector<int> &nums, int lower, int upper) {
        int n = nums.size();
        vector<LL> preSum(n + 1, 0);
        for (int i = 1; i <= nums.size(); i++) preSum[i] = preSum[i - 1] + nums[i - 1];
        for (LL x:preSum) {
            vals.PB(x);
            vals.PB(x - lower);
            vals.PB(x - upper);
        }
        map<LL, int> values;
        int idx = 0;
        for (LL x:vals) {
            values[x] = idx;
            idx++;
        }
        int ans = 0;
        int l = 0, r = vals.size() - 1;
        tree = new SegTree();
        SegTreeNode *root = new SegTreeNode(l, r);
        tree->init(root, l, r);
        for (LL x:preSum) {
            int l = values[x - lower], r = values[x - upper];
            ans += tree->queryRange(root, l, r);
            tree->updateSingle(root, values[x], values[x]);
        }
        return ans;
    }

    // tag:divide conquer
    int _countRangeSum01(vector<int> &nums, int lower, int upper) {

    }
};

