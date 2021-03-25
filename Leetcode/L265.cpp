#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// https://youtu.be/KVfQmGiwEMU
class Solution {
public:
    int minCostⅡ(vector<vector<int>> &costs) {
        int N = costs.size();
        if (N == 0) return 0;
        int K = costs[0].size();
        auto dp = vector<vector<int>>(N, vector<int>(K, 0));
        for (int k = 0; k < K; k++) {
            dp[0][k] = costs[0][k];
        }
        for (int i = 1; i < N; i++) {
            vector<pair<int, int>> temp;
            for (int k = 0; k < K; k++) temp.push_back({dp[i - 1][k], k});
            sort(temp.begin(), temp.end());
            for (int k = 0; k < K; k++) {
                if (k != temp[0].second) {
                    dp[i][k] = costs[i][k] + temp[0].first;
                } else {
                    dp[i][k] = costs[i][k] + temp[1].first;
                }
            }
        }
        int ans = INT_MAX;
        for (int k = 0; k < K; k++) {
            ans = min(ans, dp[N - 1][k]);
        }
        return ans;
    }
};

int main() {
    Solution INSTANCE;
    vector<vector<int>> temp{{1, 5, 3},
                             {2, 9, 4}};
    cout << "粉刷房子2\t" << INSTANCE.minCostⅡ(temp) << endl;
    return 0;
}