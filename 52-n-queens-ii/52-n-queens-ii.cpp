class Solution {
public:
  
  bool check(int n, int i, int j, vector<vector<int> >& board) {
    // check same column
    for (int ii = i - 1; ii >= 0; ii--) 
      if (board[ii][j] == 1) return false;

    // check LeftDiagonal
    int ii = i - 1;
    int jj = j - 1;
    while (ii >= 0 and jj >= 0) {
      if (board[ii][jj]) return false;
      ii--;
      jj--;
    }

    // check rightDiagonal
    ii = i - 1;
    jj = j + 1;
    while (ii >= 0 and jj < n) {
      if (board[ii][jj]) return false;
      ii--;
      jj++;
    }
    return true;
  }

  int ways(int n, int i, vector<vector<int> >&board) {
    if (i == n) {
      return 1;
    }

    int ans = 0;
    for (int j = 0; j < n; j++) {
      if (check(n, i, j, board)) {
        board[i][j] = 1;
        ans += ways(n, i + 1, board);
        board[i][j] = 0;
      }
    }

    return ans;
  }

  int totalNQueens(int n) {
    vector<vector<int>> board(n, vector<int> (n,0));
    return ways(n, 0, board);
  }
};
