#include <vector>
#include <iostream>
#include <functional>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> ans;
        const int n = S.length();
        function<bool(int)> dfs = [&](int pos) -> bool {
            if (pos == n) return ans.size() >= 3;
            long num = 0;
            int maxLen = S[pos] == '0' ? 1 : 10;
            for (int i = pos; i < min(pos + maxLen, n); i++) {
                num = num * 10 + S[i] - '0';
                if (num > INT_MAX) return false;
                if (ans.size() >= 2) {
                    // long sum =  ans.rbegin()[0] +  ans.rbegin()[1]; // 会出现overflow ERROR。
                    long sum = (long) ans.rbegin()[0] + (long) ans.rbegin()[1];
                    if (num > sum)break;
                    else if (num < sum) continue;
                }
                ans.push_back(num);
                if (dfs(i + 1)) return true;
                ans.pop_back();
            }
            return false;
        };
        dfs(0);
        return ans;
    }

};

int main() {
    Solution INSTANCE;
    vector<int> ans = INSTANCE.splitIntoFibonacci("123456579");
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\t";
    }
    cout << endl;
    return 0;
}