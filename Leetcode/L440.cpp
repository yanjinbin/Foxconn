#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        k--;
        while (k > 0) {
            int gap = findGap(n, cur, cur + 1);
            if (gap <= k) {
                cur = cur + 1;// 邻居点
                k -= gap;
            } else {//下一层
                cur *= 10;
                k = k - 1;
            }
        }
        return cur;
    };
    // 计算 [cur,neighbour) 区间的个数
    int findGap(long n, long cur, long neighbour) {
        int gap = 0;
        while (cur <= n) {
            gap += min(n + 1, neighbour) - cur;
            cur = cur * 10;
            neighbour = neighbour * 10;
        }
        return gap;
    }
};

int main() {}