class Solution {
  public:
  int dp[1005][1005];
  string a;
  string b;
  int n = a.size();
  int m = b.size();

  int rec(int i, int j) {
    if (i == n) return 0;
    if (j == m) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    int ans = 0;
    if (a[i] == b[j]) ans = 1 + rec(i + 1, j + 1);
    else ans = max(rec(i + 1, j), rec(i, j + 1));

    return dp[i][j] = ans;
  }

  int LCSIterative() {
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 or j == 0) dp[i][j] = 0;
            else if(a[i - 1] == b[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    return dp[n][m];
  }

  int longestCommonSubsequence(string text1, string text2) {
    memset(dp, -1, sizeof(dp));
    a = text1;
    n = text1.size();
    b = text2;
    m = text2.size();

    return rec(0, 0);
    // return LCSIterative();
  }
};

