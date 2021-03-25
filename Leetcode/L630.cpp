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

// tag: 优先队列, //deadline排序  指定时间内,安排最多的课程,如果新加入的课c1与之前课程时长最小c2的冲突,那么丢弃max(c1,c2)课程时长的那门课程
class Solution {
public:
    int scheduleCourse(vector<vector<int>> &courses) {
        sort(courses.begin(), courses.end(), [](const vector<int> &v1, const vector<int> &v2) {
            return v1[1] < v2[1];
        });// 按DDL升序
        int d = 0;
        int cnt = 0;
        priority_queue<int> q;
        for (vector<int> v:courses) {
            if (d + v[0] <= v[1]) {
                cnt++;
                d = d + v[0];
                q.push(v[0]);
            } else if (q.size() && q.top() >= v[0]) {
                d = d + v[0] - q.top();
                q.pop();
                q.push(v[0]);
            }
        }
        return cnt;
    }
};

int main() {
    Solution INSTANCE;
    vector <vector<int>> vals = {{}};
    int ans = INSTANCE.scheduleCourse(vals);
    cout << ans << endl;
}

