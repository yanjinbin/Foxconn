#include <vector>
#include <iostream>

using namespace std;
#define debug puts("pigtoria bling bling ⚡️⚡️");

// https://atcoder.jp/contests/abc195/editorial/897
// tips: and | or , in reverse order.
int main() {
    int N;
    string S, X, T;
    cin >> N >> S >> X;
    bool win;
    vector <vector<bool>> dp(N + 1, vector<bool>(7, false));// t win
    dp[N][0] = true;// 无论之前是什么样子，只要最后是7的base，那么，肯定是T win
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < 7; j++) {
            int j1 = (j * 10) % 7, j2 =((j * 10) + S[i] - '0') % 7;
            if (X[i] == 'A') {
                if (dp[i + 1][j1] && dp[i + 1][j2]) {// 因为是A 所以and
                    dp[i][j] = true;
                }
            } else {
                if (dp[i + 1][j1] || dp[i + 1][j2]) {
                    dp[i][j] = true;
                }
            }

        }
    }
    win = dp[0][0];
    if (win) cout << "Takahashi";
    else cout << "Aoki";
    return 0;
}