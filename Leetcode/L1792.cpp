#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>

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
    // tag: priority_queue
    double maxAverageRatio(vector<vector<int>> &classes, int k) {
        int n = classes.size();
        auto ratio = [&](int i, int delta = 0) {
            return static_cast<double>(classes[i][0] + delta ) / (classes[i][1] + delta);
        };
        priority_queue <pair<double, int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push(pair<double, int>(ratio(i, 1) - ratio(i), i));
        }
        while (k--) {
            int idx = pq.top().second;
            pq.pop();
            classes[idx][0]++;
            classes[idx][1]++;
            pq.push(pair<double, int>(ratio(idx, 1) - ratio(idx), idx));
        }
        double ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += ratio(i);
        }
        return ans / n;
    }
};

int main() {


}