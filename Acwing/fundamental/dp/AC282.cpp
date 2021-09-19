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

const int INF = 0x3F3F3F3F, MAX_VALUE = 0x7FFFFFFF, MIN_VALUE = 0x80000000, MOD = 1E9 + 7;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define debug puts("pigtoria bling bling ⚡️⚡️");
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define LL long long
#define LD long double
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second

// dp(i,j)=dp(i,k)+sum(k+1,m)+dp(m+1,j)
class Solution {
public:
    int mergeStone(vector<int> arr) {

    }
};

int main() {
    int N;
    vector<int> arr;
    int val;
    while (N--) {
        cin >> val;
        arr.EB(val);
    }
    Solution INSTANCE;
    int ans = INSTANCE.mergeStone(arr);
    cout << ans << endl;
}