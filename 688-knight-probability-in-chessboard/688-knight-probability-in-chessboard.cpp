#define MAXK 101
#define MAXN 26

vector<pair<int, int>> pos = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};
double dp[MAXK][MAXN][MAXN];

class Solution {
  public:
  Solution() {
    for (int i = 0; i < MAXK; i++) {
      for (int j = 0; j < MAXN; j++) {
        for (int kk = 0; kk < MAXN; kk++) {
          dp[i][j][kk] = -1;
        }
      }
    }
  }

  double knightProbability(int n, int k, int row, int column) {
    if (k == 0)
      return 1.0;
    double ans = 0.0;
    if (dp[k][row][column] != -1)
      return dp[k][row][column];
    for (int i = 0; i < 8; i++) {
      int xx = row + pos[i].first;
      int yy = column + pos[i].second;
      if (xx >= 0 and xx < n and yy >= 0 and yy < n) {
        ans += 0.125 * knightProbability(n, k - 1, xx, yy);
      }
    }

    return dp[k][row][column] = ans;
  }
};