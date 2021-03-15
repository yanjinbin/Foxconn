#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 0X3F3F3F3F;

int main() {
    int a, b, w;
    cin >> a >> b >> w;
    w = w * 1000;
    int mi = INF;
    int mx = 0;
    for (int n = 1; n <= 1000000; n++) {
        if (a * n <= w && w <= b * n) {
            mi = min(n, mi);
            mx = max(n, mx);
        }
    }
    if (mx == 0) cout << "UNSATISFIABLE";
    else cout << mi << " " << mx;
    return 0;
}

