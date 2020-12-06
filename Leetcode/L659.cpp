#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPossible(vector<int> &nums) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
        for (auto &x : nums) {
            if (mp.find(x) == mp.end()) {
                mp[x] = priority_queue<int, vector<int>, greater<int >>();
            }
            if (mp.find(x - 1) != mp.end()) {
                int prevLen = mp[x - 1].top();
                mp[x - 1].pop();
                if (mp[x - 1].empty()) {
                    mp.erase(x - 1);
                }
                mp[x].push(prevLen + 1);
            } else {
                mp[x].push(1);
            }
        }
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            priority_queue<int, vector<int>, greater<int>> queue = it->second;
            cout << it->first << endl;
            cout << queue.top() << endl;
            if (queue.top() < 3) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    return 0;
}