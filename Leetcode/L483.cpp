#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include <stack>
#include <cmath>

using namespace std;

const int INF = 0x3F3F3F3F;
const int MOD = 1E9 + 7;
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

// tag: 二分 https://youtu.be/Xy5f8IAEsJg?t=1514 https://www.cnblogs.com/grandyang/p/6620351.html
class Solution {
public:
    string smallestGoodBase(string n) {
        LL num = stol(n);
        for (int i = log(num) / log(2)+1 ; i >= 2; i--) { // +1 是因为case n = 15
            LL lo = 2, hi = pow(num, 1.0 / (i - 1)) + 1;
            while (lo < hi) {
                LL mid = (hi - lo) / 2 + lo;
                LL sum = 0;
                for (int j = 0; j < i; j++) {
                    sum = sum * mid + 1;
                }
                if (sum == num) return to_string(mid);
                else if (sum < num) lo = mid + 1;
                else hi = mid;
            }
        }
        return to_string(num - 1);
    }
};

int main() {
    fastio
    Solution INSTANCE;
    string ans = INSTANCE.smallestGoodBase("15");
    cout << ans << endl;
    int i = log(15) / log(2) +1;
    double ret = pow(15, 1.0 / (i - 1));
    cout << i << " " << ret << endl;
    return 0;
}