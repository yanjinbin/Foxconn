#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <stack>

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


class FenwickTree {
public:
    FenwickTree(int n) : sums_(n + 1, 0) {}

    void update(int i, int delta) {
        while (i < sums_.size()) {
            sums_[i] += delta;
            i += lowbit(i);
        }
    }

    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += sums_[i];
            i = i - lowbit(i);
        }
        return sum;
    }

private:
    static inline int lowbit(int x) { return x & (-x); }

    vector<int> sums_;
};

class Solution {
public:
    // Fen-wick tree https://youtu.be/2SVLYsq5W8M?t=561
    vector<int> countSmaller(vector<int> &nums) {
        set<int> sorted(nums.begin(), nums.end());
        map<int, int> ranks;
        int rank = 0;
        for (const int num:sorted) {
            ranks[num] = ++rank;
        }
        vector<int> ans;
        FenwickTree tree(ranks.size());
        for (int i = nums.size() - 1; i >= 0; i--) {
            int rk = ranks[nums[i]];
            ans.EB(tree.query(rk - 1));
            tree.update(rk, 1);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    vector<int> _countSmaller01(vector<int> &nums) {// 超时了
        int n = nums.size();
        vector<int> ans(n);
        if (n == 0) return ans;
        vector<int> sorted(n);
        for (int i = n - 1; i >= 0; i--) {
            int idx = lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin();
            sorted.insert(sorted.begin() + idx, nums[i]);
            ans[i] = idx;
        }
        return ans;
    }

    // tag:divide-conquer
    vector<int> _countSmaller02(vector<int> &nums) {//

    }
};

int main() {
    fastio
    Solution INSTANCE;
    vector<int> nums = {5, 2, 6, 1};
    vector<int> ans = INSTANCE.countSmaller(nums);
    FOR(i, 0, ans.size())cout << ans[i] << endl;
    return 0;
}