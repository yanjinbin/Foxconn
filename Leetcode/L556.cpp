#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
   public:
    int nextGreaterElement(int n) {
        if (n == 0 || n > INT_MAX) return -1;
        vector<int> digits;
        while (n > 0) {
            digits.push_back(n % 10);
            n = n / 10;
        }
        int i = 1;
        while (i < digits.size() && digits[i] >= digits[i - 1])
            i++;  // 从右往左，找到第一个不是递增的位数
        if (i == digits.size()) return -1;
        int j = 0;
        while (digits[j] <= digits[i]) j++;
        swap(digits[i], digits[j]);
        sort(digits.begin(), digits.begin() + i);
        reverse(digits.begin(), digits.begin() + i);
        long ret = 0;
        for (int k = digits.size() - 1; k >= 0; k--) {
            ret = ret * 10 + digits[k];
        }
        if (ret > INT_MAX)
            return -1;
        else
            return ret;
    }
};
// https://youtu.be/OKNpknDO86U
int main() {
    Solution INSTANCE;
    cout << INSTANCE.nextGreaterElement(37986251) << endl;
    return 0;
}