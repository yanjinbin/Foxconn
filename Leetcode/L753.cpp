#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>
#include <unordered_map>

using namespace std;


class Solution {
public:
    // https://github.com/wisdompeak/LeetCode/tree/master/Hash/753.Cracking-the-Safe
    // https://youtu.be/fjxhMLJjC3Y?t=717
    string crackSafe01(int n, int k) {
        string ans;
        ans.assign(n - 1, '0');
        unordered_map<string, int> record;
        int total = pow(k, n);
        for (int i = 0; i < total; i++) {
            string key = ans.substr(ans.size() - (n - 1), (n - 1));
            record[key] = (record[key] + 1) % k;
            ans += '0' + record[key];
        }
        return ans;
    }

    // https://en.wikipedia.org/wiki/De_Bruijn_sequence
    // http://zxi.mytechroad.com/blog/graph/leetcode-753-cracking-the-safe/
    // 传统的dfs backtracking方法
public:
    string crackSafe02(int n, int k) {
        const int total_size = pow(k, n) + n - 1;
        string ans(n, '0');
        unordered_set<string> seen{ans};
        if (dfs(ans, total_size, n, k, seen))return ans;
        return "";
    }

private:
    bool dfs(string &ans, const int total_len, const int n, const int k, unordered_set<string> &seen) {
        if (ans.length() == total_len) {
            return true;
        }
        string node = ans.substr(ans.length() - n + 1, n - 1);
        for (char c = '0'; c < '0' + k; c++) {
            node.push_back(c);
            if (!seen.count(node)) {
                ans.push_back(c);
                seen.insert(node);
                if (dfs(ans, total_len, n, k, seen)) return true;
                seen.erase(node);
                ans.pop_back();
            }
            node.pop_back();
        }
        return false;
    }
};


int main() {
    Solution INSTANCE;
    cout << INSTANCE.crackSafe01(3, 2) << endl;
    cout << INSTANCE.crackSafe02(3, 2) <<endl;
    return 0;
}
