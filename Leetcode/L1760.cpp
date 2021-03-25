#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 0x3F3F3F3F;
#define debug puts("pigtoria bling bling ⚡️⚡️");
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ll long long
#define pii pair<int, int>

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = *max_element(nums.begin(),nums.end()) + 1;
        while(l<r){
            int m = l + (r-l)/2;
            int ops = 0;
            for(int x:nums){
                ops +=(x+m-1)/m-1;// 向上取整-1
            }
            if(ops > maxOperations){ // 返回≤的l
                l = m+1;
            }else {
                r = m;
            }
        }
        return l;
    }
};

int main(){

}