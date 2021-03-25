#include <algorithm>
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
    // *
    //     * 思路：
    //     *  1、把这三个数字排序
    //     *  2、找到最大的次数
    //     *      max = 最大数 - 最小数 - 2
    //     *
    //     *  3、找到最小的次数
    //     *      3-1:如果三个数是连续的 1 2 3，            最小数 ： 0
    //     *      3-2:如果有两个数之前的差是1、或者2，      最小数 :  1
    //     *          eg: 1 55 56   ->   54 55 56
    //     *              1 3 56    ->   1 2 3
    //     *      3-3: 其它的                                最小数 : 2
    //     *          eg:  1  23 55  ->    22 23 24
    //     *
    vector<int> numMovesStones(int a, int b, int c) {
        // bubble sort
        if (b < a) swap(a, b);
        if (c < b) swap(b, c);
        if (b < a) swap(a, b);

        if(b-a==1&&c-b==1) return vector<int>{0,c-a-2};
        if(c-b<=2||b-a<=2) return vector<int>{1,c-a-2};
        return vector<int>{2,c-a-2};
    }
};
int main() { return 0; }