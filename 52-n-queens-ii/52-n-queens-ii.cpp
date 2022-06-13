class Solution {
  public:
  vector<int> col;
  vector<int> lDiagonal;
  vector<int> rDiagonal;

  bool check(int n, int r, int c) {
    return col[c] == 0 and lDiagonal[r - c + n - 1] == 0 and rDiagonal[r + c] == 0;
  }

  int ways(int n, int i) {
    if (i == n) {
      return 1;
    }

    int ans = 0;
    for (int j = 0; j < n; j++) {
      if (check(n, i, j)) {
        col[j] = 1;
        lDiagonal[i-j + n - 1] = 1;
        rDiagonal[i+j] = 1;
        ans += ways(n, i + 1);
        col[j] = 0;
        lDiagonal[i-j + n - 1] = 0;
        rDiagonal[i+j] = 0;
      }
    }

    return ans;
  }

  int totalNQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    col = vector<int>(n, 0);
    // r - c (range [-(n-1), n-1]) => always add n-1 to normalize
    lDiagonal = vector<int>(2 * n - 1, 0);
    rDiagonal = vector<int>(2 * n - 1, 0);  // r + c (range [0, n-1 + n-1])
    return ways(n, 0);
  }
};