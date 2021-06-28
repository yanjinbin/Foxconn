#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <cmath>
#include <climits>

using namespace std;
const int MAX_VALUE = 0x7FFFFFFF, MIN_VALUE = 0x80000000, INF = 0x3F3F3F3F, kMod = 1E9 + 7;
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
#define SE secondk

// https://youtu.be/UEzJcLSX_fU?t=609
// xyzzyx % 11 =0
// xyzyx
class Solution {
public:
    int primePalindrome(int N) {
        //特判
        if (N <= 2)return 2;
        if (N <= 3)return 3;
        if (N <= 5)return 5;
        if (N <= 7)return 7;
        if (N <= 11)return 11;

        string M = to_string(N);
        int n = M.size() / 2;
        int st = pow(10, n);
        for (int i = st; i <= 20000; i++) {
            string s = to_string(i);
            string s1 = s.substr(0, s.size() - 1);
            reverse(s1.begin(), s1.end());
            s = s + s1;
            int k = stoi(s);
            if (k >= N && quickPrime(k)) return k;
        }
        return -1;
    }

    bool isPrime(int k) {
        if (k % 2 == 0)return k == 2;
        for (int i = 3; i * i <= k; i += 2) {
            if (k % i == 0)return false;
        }
        return true;
    }

    //
    bool quickPrime(int num) {
        if (num <= 3) {
            return num > 1;
        }
        // 不在6的倍数两侧的一定不是质数
        if (num % 6 != 1 && num % 6 != 5) {
            return false;
        }
        int hi =  sqrt(num);
        for (int i = 5; i <= hi; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
};