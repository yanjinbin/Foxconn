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
#define speedio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
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

class NumArray {

    class SegTreeNode {
    public:
        SegTreeNode *left;
        SegTreeNode *right;
        int start, end;
        int info;

        SegTreeNode(int a, int b) : start(a), end(b), info(0), left(NULL), right(NULL) {}
    };

    void init(SegTreeNode *node, int a, int b)  // init for range [a,b]
    {
        if (a == b) {
            node->info = nums[a];
            return;
        }
        int mid = (a + b) / 2;
        if (node->left == NULL) {
            node->left = new SegTreeNode(a, mid);
            node->right = new SegTreeNode(mid + 1, b);
        }
        init(node->left, a, mid);
        init(node->right, mid + 1, b);

        node->info = node->left->info + node->right->info;  // write your own logic
    }

    void updateSingle(SegTreeNode *node, int id, int val) {
        if (id < node->start || id > node->end)return;
        if (node->start == node->end) {
            node->info = val;
            return;
        };
        updateSingle(node->left, id, val);
        updateSingle(node->right, id, val);//后续遍历
        node->info = node->left->info + node->right->info;
    }

    int queryRange(SegTreeNode *node, int l, int r) {
        if (l > node->end || r < node->start) {
            return 0;
        }
        if (l <= node->start && node->end <= r) {
            return node->info;
        }
        return queryRange(node->left, l, r) + queryRange(node->right, l, r);
    }

    vector<int> nums;
    SegTreeNode *root;

public:
    NumArray(vector<int> &nums) {
        this->nums = nums;
        root = new SegTreeNode(0, nums.size() - 1);
        init(root, 0, nums.size() - 1);
    }

    void update(int index, int val) {
        updateSingle(root, index, val);
    }

    int sumRange(int left, int right) {
        return queryRange(root, left, right);
    }
};

// tag:线段树 segement tree
int main() {
    speedio
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    NumArray INSTANCE{nums};
    INSTANCE.update(0, 0);
    int ans = INSTANCE.sumRange(0, 3);
    cout << ans << endl;
    return 0;
}