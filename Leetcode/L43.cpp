#include "../QuikTemplate.cpp"

class Solution {
public:
    string multiply(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (n == 0 || m == 0) return 0;
        vector<int> ret(n + m, 0);
        for (int i = n - 1; i >= 0; i--) {
            int c1 = s1[i] - '0';
            for (int j = m - 1; j >= 0; j--) {
                int c2 = s2[j] - '0';
                int sum = ret[i + j + 1] + c1 * c2;
                ret[i + j + 1] = sum % 10;
                ret[i + j] += sum / 10;
            }
        }
        string ans;
        for (int i = 0; i < n + m; ++i) {
            if (ret[i] == 0 && ans.size() == 0) continue;// 忽略前导0
            ans.PB(ret[i] + '0');
        }
        return ans.size() == 0 ? "0" : ans;
    }
};