#include <vector>
#include <iostream>
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

int main() {
    ready
    int st, ed;
    cin >> st >> ed;
    int n;
    cin >> n;
    vector <pii> vp;
    while (n--) {
        int a, b;
        cin >> a >> b;
        vp.EB(make_pair(a, b));
    }
    sort(vp.begin(), vp.end());
    int res = 0;
    bool success = false;
    int len = vp.size();
    int i = 0;
    while (i < len) {
        int j = i, r = -INF;
        while (j < len && vp[j].first <= st) {
            r = max(r, vp[j].second);
            j = j + 1;
        }
        if (r < st) {
            res = -1;
            break;
        }
        res++;
        if (r >= ed) {
            success = true;
            break;
        }
        st = r; // update start by r
        i = j;
    }
    if (success) cout << res << endl;
    else cout << -1 << endl;
    return 0;
}