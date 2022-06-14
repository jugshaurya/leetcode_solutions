class Solution {
  public:
  int memo[1005][1005];
  int LCS(string &a, string &b, int i = 0, int j = 0) {
    int A = a.size();
    int B = b.size();
      
    if (i == A) return 0;
    if (j == B) return 0;
      
    if (memo[i][j] != -1) return memo[i][j];
    
    if (a[i] == b[j]) return memo[i][j] = 1 + LCS(a, b, i + 1, j + 1);
    return memo[i][j] = max(LCS(a, b, i + 1, j), LCS(a, b, i, j + 1));
  }

  int LCSIterative(string &a, string &b) {
    int n = a.length();
    int m = b.length();

    vector<vector<int> > memo(n + 1, vector<int>(m + 1, 0));
      
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i - 1] == b[j - 1]) memo[i][j] = 1 + memo[i - 1][j - 1];
            else memo[i][j] = max(memo[i][j - 1], memo[i - 1][j]);
      
    return memo[n][m];
  }

  int longestCommonSubsequence(string text1, string text2) {
    memset(memo, -1, sizeof(memo));
    return LCSIterative(text1, text2);
  }
};
