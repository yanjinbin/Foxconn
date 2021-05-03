#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <stack>
#include <cmath>

using namespace std;

const int MAX_VALUE = 0x7FFFFFFF, MIN_VALUE = 0x80000000, INF = 0x3F3F3F3F, MOD = 1E9 + 7;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define debug puts("pigtoria bling bling ⚡️⚡️");
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define pii pair<int, int>
#define LL long long
#define LD long double
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second

// tag:math
// https://youtu.be/Bdw2Y9FrqcU?t=589
// D是偶数
//① 1 2 3 4 5 , K = 5, T = 15,  D=0
//② 1 2 3 4 5 , K = 5 , T = 11 , D = 4, 1 -2 3 4 5

// d是奇数, k 分奇偶
//③ 1 2 3 4 5 6 , k = 6, T = 18 , d = 3 --> 1 2 3 4 -5 6 7 , i=5,k=7,
//④ 1 2 3 4 5 6 7, k= 7 , T =23 , D = 5 ---> 1 2 -3 4 5 6 7 -8 9
class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int sum = 0;
        int k = 0;
        while (sum < target)sum += (++k);
        int d = sum - target;
        if (d % 2 == 0) return k;
        else return (k + 1 + (k % 2));
    }

    int reachNumber_(int target) {
        target = abs(target);
        int k = sqrt(target);
        while (sum(k) < target)k++;
        int d = sum(k) - target;
        if (d % 2 == 0)return k;
        else return (k + 1 + (k % 2));

    }

    int sum(int k) {
        return (k * (k + 1)) / 2;
    }
};