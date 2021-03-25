#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int res = 0, N = s.length(), maxIdx = 0;
        vector<int> cnt(26, 0);
        bool ok = true;
        for (int i = 0; i < N; i++) cnt[s[i] - 'a']++;
        for (int i = 0; i < N; i++) {
            if (cnt[s[i] - 'a'] < k) {
                res = max(res, longestSubstring(s.substr(maxIdx, i - maxIdx), k));
                maxIdx = i + 1;
                ok = false;
            }
        }
        return ok ? N : max(res, longestSubstring(s.substr(maxIdx, N - maxIdx), k));
    }
};

int main() {
    Solution INSTANCE;
    cout << INSTANCE.longestSubstring("abababcdeefrrfd", 2);
    return 0;
}
