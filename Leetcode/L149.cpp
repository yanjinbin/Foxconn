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

class Solution {
public:
    int maxPoints(vector<vector<int>> &points) {
        int len = points.size();
        int ans = 0;
        for (int i = 0; i < len; i++) {
            map<pii, int> count;
            int same_point = 1;
            int max_point = 0;
            vector<int> p1 = points[i];
            for (int j = i + 1; j < len; j++) {// 为什么j从i+1开始,之前已经计算过了就不用重复计算了啊!
                vector<int> p2 = points[j];
                if (p1[0] == p2[0] && p1[1] == p2[1]) {
                    same_point++;
                } else {
                    pii key = slope(p1, p2);
                    max_point = max(max_point, ++count[key]);// 局部最优解
                }
            }
            ans = max(ans, max_point + same_point);
        }
        return ans;
    }
    // {dy,dx}
    pii slope(const vector<int> &p1, const vector<int> &p2) {
        const int dx = p2[0] - p1[0];
        const int dy = p2[1] - p1[1];
        if (dy == 0) return {p1[1], 0};
        if (dx == 0) return {0, p1[0]};
        const int d = gcd(dx, dy);
        return {dy / d, dx / d};
    }

    int gcd(int m, int n) {
        return n == 0 ? m : gcd(n, m % n);
    }
};

// 点评如何求斜率,用到gcd方法
// https://youtu.be/7FPL7nAi9aM  类似L1610

int main() {
    return 0;
}