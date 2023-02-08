#include "../QuikTemplate.cpp"

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