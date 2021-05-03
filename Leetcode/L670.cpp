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
#define SE second

// CASE 993276->997236
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        string t = s;
        sort(t.begin(), t.end());
        reverse(t.begin(), t.end());
        int pos = 0, i = 0;
        for (; i < s.size(); ++i) {
            if (s[i] != t[i]) {
                break;
            }
        }
        if (i == s.size())return num;
        //general
        for (int j = i + 1; j < s.size(); j++) {
            if (s[j] == t[i]) pos = j;
        }
        swap(s[i], s[pos]);
        return stoi(s);
    }
};