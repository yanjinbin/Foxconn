#include <vector>

using namespace std;

const int INF = 0x3F3F3F3F;
const int MOD = 1E9 + 7;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
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

//  下标从1开始
// https://youtu.be/WbafSgetDDk?t=497
// tag:树状数组/Binary indexed Tree/Fenwick Tree
class FenwickTree {
public:
    FenwickTree(int n) : sums_(n + 1, 0) {}

    void update(int i, int delta) {
        while (i < sums_.size()) {
            sums_[i] += delta;
            i += lowbit(i);// 代表i位置的parent节点位置
        }
    }

    int query(int i) const {
        int sum = 0;
        while (i > 0) {
            sum += sums_[i];
            i -= lowbit(i);
        }
        return sum;
    }

private:
    static inline int lowbit(int x) { return x & (-x); }
    vector<int> sums_;
};
