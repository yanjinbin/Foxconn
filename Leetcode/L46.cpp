#include <vector>
#include <iostream>
#include <functional>

#define FOR(i, a, b) for (int i = a; i < b; i++)
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int> nums) {
        const int N = nums.size();
        vector<vector<int>> ans;
        vector<bool> used(N, false);
        vector<int> path;
        function<void(int)> dfs = [&](int cur) {
            if (cur == N) {
                ans.push_back(path);
                return;
            }
            for (int i = 0; i < N; i++) {
                if (used[i])continue;
                used[i] = true;
                path.push_back(nums[i]);
                dfs(cur + 1);
                path.pop_back();
                used[i] = false;
            }
        };
        dfs(0);
        return ans;
    }
};

int main() {
    Solution INSTANCE;
    vector<int> nums = {1, 2, 3, 4};
    vector<vector<int>> ans = INSTANCE.permute(nums);
    FOR(i, 0, ans.size()) {
        FOR(j, 0, ans[i].size()) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

