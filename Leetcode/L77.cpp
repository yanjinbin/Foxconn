#include <vector>
#include <iostream>
#include <functional>

#define FOR(i, a, b) for (int i = a; i < b; i++)
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cur;
        function<void(int)> dfs = [&](int s) {
            if (cur.size() == k) {
                ans.push_back(cur);
                return;
            }
            for (int i = s; i < n; i++) {
                cur.push_back(i);
                dfs(i + 1);
                cur.pop_back();
            }
        };
        dfs(0);
        return ans;
    }

    vector<vector<int>> combine02(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(1, n, ans, cur, k);
        return ans;
    }

    void dfs(int cur, int n, vector<vector<int>> &ans, vector<int> &tmp, int k) {
        if (tmp.size() == k) {
            ans.push_back(tmp);
            return;
        }
        for (int i = cur; i <= n; i++) {
            tmp.push_back(i);
            dfs(i + 1, n, ans, tmp, k);
            tmp.pop_back();
        }
    }
};

int main() {
    Solution INSTANCE;
    vector<vector<int>> ans = INSTANCE.combine02(5, 3);
    vector<vector<int>> res = INSTANCE.combine(5, 3);
    FOR(i, 0, ans.size()) {
        FOR(j, 0, ans[i].size()) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

