#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include <stack>
#include <numeric>

using namespace std;

const int MAX_VALUE = 0x7FFFFFFF, MIN_VALUE = 0x80000000, INF = 0x3F3F3F3F, kMod = 1E9 + 7;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define debug puts("⚡️⚡️ bling bling ⚡️⚡️");
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define pii pair<int, int>
#define LL long long
#define LD long double
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second

// 分发糖果 https://youtu.be/QzPWc0ilEek?t=415
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n =ratings.size();
        vector<int> f(n,1);
        // a&b 构成了充分必要条件.
        for(int i=1;i<n;i++){ // a condition
            if (ratings[i]>ratings[i-1]){
                f[i]=max(1,f[i-1]+1);
            }
        }
        for(int i=n-2;i>=0;i--){// b condition
            if (ratings[i]>ratings[i+1]){
                f[i]=max(f[i],f[i+1]+1);
            }
        }
        int sum = accumulate(f.begin(),f.end(),0);
        return sum;
    }
};