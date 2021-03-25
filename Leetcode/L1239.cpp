#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
const int INF = 0x3F3F3F3F;
#define debug puts("pigtoria bling bling ⚡️⚡️");
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ll long long
#define pii pair<int, int>

class Solution {
public:
    int maxLength(vector<string> &arr) {
        vector<int> a;
        for (const string &x:arr) {
            int mask = 0;
            for (char c:x) {
                mask |= 1 << (c - 'a');// 不是1 >> (c-'a');哦
            }
            if (__builtin_popcount(mask) != x.length()) continue;//有重复元素
            a.push_back(mask);
        }
        int ans = 0;
        function<void(int, int)> dfs = [&](int s, int mask) {
            ans = max(ans, __builtin_popcount(mask));
            for (int i = s; i < a.size(); i++) {
                if ((mask & a[i]) == 0)
                    dfs(i + 1, mask | a[i]);
            }
        };
        dfs(0, 0);
        return ans;
    }
};

int main() {
    int ans = 1 << 2;
    cout << ans;
    return 0;
}