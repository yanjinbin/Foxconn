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
#define SE second

class Solution {
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int K) {
        vector<pair<double,int>> q;
        for(int i=0;i<quality.size();i++){
            q.PB({1.0*wage[i]/quality[i],quality[i]});
        }
        sort(q.begin(),q.end());
        double ans = INT_MAX;
        priority_queue<int> maxHeap;
        int totalQua = 0;
        for(int i=0;i<q.size();i++){
            totalQua +=q[i].second;
            maxHeap.push(q[i].second);
            if(maxHeap.size()>=K){
                double unitWage = q[i].first;
                ans = min(ans,unitWage*totalQua);
                totalQua -=maxHeap.top();maxHeap.pop();
            }
        }
        return ans;
    }
};