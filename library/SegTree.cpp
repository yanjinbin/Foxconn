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
#define debug puts("⚡️⚡ bling bling ⚡️⚡️");
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define pii pair<int, int>
#define LL long long
#define LD long double
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second

class SegTree {
    class SegTreeNode {
    public:
        SegTreeNode *left;
        SegTreeNode *right;
        int start, end;
        int info;

        SegTreeNode(int l, int r) : start(l), end(r), info(0), left(NULL), right(NULL) {}
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
    }

    vector<int> nums;
    SegTreeNode *root;
};


