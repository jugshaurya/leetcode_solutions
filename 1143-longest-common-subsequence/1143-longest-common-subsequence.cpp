class Solution {
public:
  int memo[1005][1005];
  int LCS(string a, string b) {
      int A = a.size();
      int B = b.size();
      if (a.size() == 0) return 0;
      if (b.size() == 0) return 0;
      if (memo[A][B] != -1) return memo[A][B];
      if (a[0] == b[0]) return 1 + LCS(a.substr(1), b.substr(1));
      return memo[A][B] = max(LCS(a.substr(1), b), LCS(a, b.substr(1)));
  }

  int LCSIterative(string a, string b) {
      int n = a.length();
      int m = b.length();

      int memo[n+1][m+1];
      for (int i = 0; i <= n; i++) memo[i][0] = 0;
      for (int i = 0; i <= m; i++) memo[0][i] = 0;
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
