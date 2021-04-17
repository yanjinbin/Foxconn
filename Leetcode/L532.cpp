#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include <stack>

using namespace std;

const int INF = 0x3F3F3F3F;
const int MOD = 1E9 + 7;
#define ready ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
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
    int findPairs(vector<int> &nums, int k) {
        if (k < 0) return 0;
        unordered_set<int> saw, diff;
        for (int i = 0; i < nums.size(); ++i) {
            int key = nums[i];
            if (saw.count(key - k)) {
                diff.insert(key - k);
            }
            if (saw.count(i + k)) {
                saw.insert(key);
            }
            saw.inser(key);
        }
        return diff.size();
    }

    int _findPairs(vector<int> &nums, int k) {
        unordered_map<int, int> map;
        int count = 0;
        if (k < 0) return 0;
        if (k == 0) {
            for (int key:nums) {
                map[key]++;
                if (map[key] == 2) count++;
            }
            return count;
        }
        // k > 0;

        for (int i = 0; i < nums.size(); ++i) map[nums[i]]++;
        for (int i = 0; i < nums.size(); ++i) {
            int key = nums[i];
            if (map.count(key - k)) {// 存在 k-diff
                if (map[key] != -1) {
                    count++;
                    map[key] = -1;// -1 代表已经访问过了,无需下次再处理
                }
            }
        }
        return count;
    }
};