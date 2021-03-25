#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;
const int INF = 0x3F3F3F3F;
#define debug puts("pigtoria bling bling ⚡️⚡️");
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ll long long
#define pii pair<int, int>

class Solution {
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int X) {
        int leftsum = 0, winsum = 0, rightsum = 0, len = customers.size();
        for (int i = X; i < len; i++) {
            if (grumpy[i] == 0) {
                rightsum += customers[i]; // 右边
            }
        }
        for (int i = 0; i < X; i++) {// 窗口
            winsum += customers[i];
        }
        int l = 1, r = X; // left right margin
        int ans = leftsum + winsum + rightsum;
        while (r < len) {
            if (grumpy[l - 1] == 0) { // l-1 poll in
                leftsum += customers[l - 1];
            }
            if (grumpy[r] == 0) { // r poll out
                rightsum -= customers[r];
            }
            winsum = winsum - customers[l - 1] + customers[r];
            ans = max(ans,leftsum+winsum+rightsum);
            // iterator update
            l++;
            r++;
        }
        return ans;
    }
};

int main() {

}