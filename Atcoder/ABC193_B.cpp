#include <iostream>

using namespace std;
const int INF = 1E9 + 7;

int main() {
    int N;
    cin >> N;
    int ans = INF;
    int ai, pi, xi;
    while (N--) {
        cin >> ai >> pi >> xi;
        if (xi > ai) {
            ans = min(ans, pi);
        }
    }
    if (ans == INF)
        cout << -1;
    else
        cout << ans << endl;

    return 0;
}