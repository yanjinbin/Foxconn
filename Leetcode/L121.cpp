#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int INF = 0x3F3F3F;
        int minPrice = INF;
        int ans = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } else if (prices[i] - minPrice > ans) {
                ans = prices[i] - minPrice;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> price = {7, 1, 5, 3, 6, 4};
    Solution INSTANCE;
    cout << INSTANCE.maxProfit(price) << endl;
    return 0;
}