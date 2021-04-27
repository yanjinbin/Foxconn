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

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7
// TAG: 拒绝采样
class Solution {
public:
    int rand10() {
        int num = MAX_VALUE;
        while (num >= 40) {
            num = (rand7() - 1) * 7 + rand7() - 1;
        }
        return num % 10 + 1;
    }

    int rand7() { return -1; }
};