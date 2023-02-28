#include "../QuikTemplate.cpp"

class Solution {
public:
  // 877 石头游戏  tag: min-max dp
  bool stoneGame(vector<int> &piles) {
    int N = piles.size();
    vector<vector<int>> dp(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
      dp[i][i] = piles[i];
    }
    for (int len = 2; len <= N; len++) {
      for (int i = 0; N - i >= len; i++) {
        int j = i + len - 1;
        dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
      }
    }
    return dp[0][N - 1];
  }

  // 在每个玩家的回合中，该玩家可以拿走剩下的 前 X 堆的所有石子，其中 1 <= X <= 2M。然后，令 M = max(M, X),所以
  // M∈[1,len] 0 << s < len , 0=<m<=len;
  //  s+2m >= len, dp[s][m]=sum[s:len-1];
  //  s+2m < len, dp[s][m]=Math.max(dp[s][M],sum[s:len-1]-dp[s+x][Max(m,x)],1<=x<=2m)  ✅
  // 由于本题中的状态是从后往前递推的，如：假如最后只剩一堆，一定能算出来最佳方案，但是剩很多堆时不好算（依赖后面的状态）。所以我们选择从后往前递推。
public
  int stoneGameII(int[] piles) {

    int n = piles.length;
    int sum = 0;
    int[][] dp = new int[n][n + 1];
    for (int i = n - 1; i >= 0; i--) {
      sum += piles[i];
      for (int m = 1; m <= n; m++) {
        if (i + 2 * m >= n) {
          dp[i][m] = sum;
        } else {
          for (int x = 1; x <= 2 * m; x++) {
            dp[i][m] = Math.max(dp[i][m], sum - dp[i + x][Math.max(m, x)]);
          }
        }
      }
    }
    return dp[0][1];
  }

  // 1140 II
  int stoneGameII(vector<int> &piles) {
    int N = piles.size();
    int sum = 0;
    vector<vector<int>> dp(N, vector<int>(N + 1, 0));
    for (int i = n - 1; i >= 0; i--) {
      sum += piles[i];
      for (int m = 1; m <= n; m++) {
        if (i + 2 * m >= n) {
          dp[i][m] = sum;
        } else {
          for (int x = 1; x <= 2 * m; x++) {
            dp[i][m] = max(dp[i][m], sum - dp[i + x][max(m, x)])
          }
        }
      }
    }
    return dp[0][1];
  }

  // 1406 III
  string stoneGameIII(vector<int> &stoneValue) {}

  // 1510 IV
  bool winnerSquareGame(int n) {}

  // 1563 V
  int stoneGameV(vector<int> &stoneValue) {}

  // 1686 VI
  int stoneGameVI(vector<int> &aliceValues, vector<int> &bobValues) {}

  // 1690 VII
  int stoneGameVII(vector<int> &stones) {}

  // 1872 VIII
  int stoneGameVIII(vector<int> &stones) {}

  // 2029 IX
  bool stoneGameIX(vector<int> &stones) {}
};