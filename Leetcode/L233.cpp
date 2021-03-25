#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        // INIT
        if (n <= 0)return 0;
        vector<int> f(10, 0), pow(10, 0);
        f[0] = 0;
        f[1] = 1;
        pow[0] = 1;
        for (int i = 1; i <= 9; i++) {
            f[i] = f[i - 1] * 10 + pow[i - 1];
            pow[i] = 10 * pow[i - 1];
        }


        string num = to_string(n);
        reverse(num.begin(), num.end());
        int ans = 0, ones = 0;
        for (int i = num.length() - 1; i >= 0; i--) {
            ans += ones * ((num[i] - '0') * pow[i]);
            if (num[i] == '1') {
                ones++;
                ans += f[i];
            } else if (num[i] != '0') {
                ans += pow[i] + f[i] * (num[i] - '0');
            }
        }
        return ans + ones;
    }
};

// https://www.acwing.com/solution/LeetCode/content/280/
int main() {
    Solution INSTANCE;
    cout << INSTANCE.countDigitOne(21301) << endl;
    return 0;
}