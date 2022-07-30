
// Bottom Up Method
class Solution {
  public:
  int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
        else dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
      }
    }

    return dp[m][n];
  }
};

// Top Down Method
// class Solution {
// public:
//     int memo[505][505];
//     // dp(i, j)
//     int recurse(int i, int j, string& word1, string& word2) {
//         int n = word1.size();
//         int m = word2.size();

//         if(i == n) return m - j;
//         if(j == m) return n - i;

//         if(memo[i][j] != -1)
//             return memo[i][j];

//         if(word1[i] == word2[j])
//             return memo[i][j] = recurse(i+1, j+1, word1, word2);

//         return memo[i][j] = 1 + min({
//             recurse(i, j+1, word1, word2),
//             recurse(i+1, j, word1, word2),
//             recurse(i+1, j+1, word1, word2)
//         });
//     }

//     int minDistance(string word1, string word2) {
//         memset(memo, -1, sizeof(memo));
//         return recurse(0, 0, word1, word2);
//     }
// };
