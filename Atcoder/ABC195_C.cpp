#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;
const int INF = 0x3F3F3F3F;
#define debug puts("pigtoria bling bling ⚡️⚡️");
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ll long long
#define pii pair<int, int>


int main() {
    ll N;
    cin >> N;
    ll ans = 0;
    if (N > 999)ans += N - 999;// 3
    if (N > 999999) ans += N - 999999;
    if (N > 999999999) ans += N - 999999999;//9
    if (N > 999999999999) ans += N - 999999999999;
    if (N > 999999999999999) ans += N - 999999999999999;//15
    cout << ans << endl;
    return 0;
}