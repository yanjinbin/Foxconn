#include <iostream>

using namespace std;

class Solution {
public:
    int NumberOf1(int n) {
        int count = 0;
        unsigned int un = n;// 设置成无符号整数 是因为 右移的时候高位不会补1，这样while不会陷入死循环
        while (un) {
            count += un & 1;
            un = un >> 1; // 高位补0;
        }
        return count;
    }

    int NumberOfOne(int n) {
        int cnt = 0;
        for (int i = 0; i < 32; i++) cnt += (n >> i) & 1;
        return cnt;
    }
};

int main() {
    Solution Instance;
    cout << Instance.NumberOf1(-2) << endl;
    cout << Instance.NumberOfOne(-2) << endl;
    return 0;
}