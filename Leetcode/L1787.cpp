#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;
const int INF = 0x3F3F3F3F;
#define debug puts("pigtoria bling bling ⚡️⚡️");
#define FOR(i, a, b) for (int i = a; i < b; i++);
#define FORd(i, a, b) for (int i = b; i >= a; i--);
#define ll long long
#define pii pair<int, int>

class Solution {
public:
    // https://bit.ly/3eFSyIk
    int minChanges(vector<int> &nums, int k) {
        int n = nums.size();
        vector <map<int, int>> groups(k);
        vector<int> size(k);
        for (int i = 0; i < k; i++) {
            for (int j = i; j < n; j += k) {
                groups[i][nums[j]]++;
                size[i]++;
            }
        }

        vector<int> dp(1 << 10, INF);
        dp[0] = 0;
        for (int i = 0; i < k; i++) {
            int lo = *min_element(dp.begin(), dp.end());
            vector<int> ndp(1 << 10, lo + size[i]);
            for (int j = 0; j < (1 << 10); j++) {
                if (dp[j] == INF) continue;
                for (auto [p,freq]:groups[i]){
                    int nxt = p ^ j;
                    ndp[nxt] = min(ndp[nxt],dp[j]+size[i]-freq);
                }
            }
            // ? ⭐
            dp = move(ndp);
        }
        return dp[0];
    }
};

int main() {

}