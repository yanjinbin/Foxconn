#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <stack>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

typedef tree<
        pair<long, int>,
        null_type,
        less<pair<long, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
const int MAX_VALUE = 0x7FFFFFFF, MIN_VALUE = 0x80000000, INF = 0x3F3F3F3F, MOD = 1E9 + 7;
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

// tag: 分治/divide-conquer
class Solution {

public:
    int ret = 0;
    vector<int> aux;

    int reversePairs(vector<int> &nums) {
        int n = nums.size();
        vector<int> &sorted = nums;
        aux = vector<int>(n);
        helper(nums, sorted, 0, n - 1);
        return ret;
    }

    void helper(vector<int> &nums, vector<int> &sorted, int lo, int hi) {
        if (lo >= hi) return;
        int mid = (hi - lo) / 2 + lo;
        helper(nums, sorted, lo, mid);
        helper(nums, sorted, mid + 1, hi);
        for (int j = mid + 1; j <= hi; ++j) {
            auto upper = upper_bound(sorted.begin() + lo, sorted.begin() + mid + 1, 2 * (long) nums[j]);// 注意不要越界
            ret += sorted.begin() + mid + 1 - upper;
        }
        // 合并排序数组(需要辅助数组aux)
        merge(nums, aux, lo, mid, hi);
    }

    void merge(vector<int> &nums, vector<int> &aux, int l, int mid, int r) {
        int i = l, j = mid + 1;
        for (int k = l; k <= r; k++) {
            aux[k] = nums[k];
        }
        for (int k = l; k <= r; k++) {
            if (i > mid) nums[k] = aux[j++];
            else if (j > r) nums[k] = aux[i++];
            else if (less(aux[i], aux[j])) nums[k] = aux[i++];
            else nums[k] = nums[j++];
        }
    }

    bool less(int p, int q) {
        return p < q;
    }

public:    // order set with index;  参考 https://youtu.be/97_B1X_jPXQ?t=1441
    int reversePairs_(vector<int> &nums) {
        int ans = 0;
        ordered_set Set;
        for (int j = 0; j < nums.size(); j++) {
            int k = Set.order_of_key({(long) nums[j] * 2 + 1, 0});// first greater or equal than
            ans += j - k;
            Set.insert({nums[j], j});// 为什么用pair呢 因为set不是multi set 不能存储重复元素
        }
        return ans;
    }
};


