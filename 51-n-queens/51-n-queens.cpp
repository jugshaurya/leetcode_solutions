class Solution {
public:
  vector<vector<string>> ans;
  
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

  void solveNQueens(int n, int i, vector<vector<int> >&board) {
    if (i == n) {
      vector<string> v;
      for (int ii = 0; ii < n; ii++) {
        string ans;
        for (int jj = 0; jj < n; jj++) 
          ans += (board[ii][jj] == 1) ? "Q" : ".";
        v.push_back(ans);
      }
      ans.push_back(v);

      return;
    }

    for (int j = 0; j < n; j++) {
      if (check(n, i, j, board)) {
        board[i][j] = 1;
        solveNQueens(n, i + 1, board);
        board[i][j] = 0;
      }
    }
    return;
  }

  vector<vector<string>> solveNQueens(int n) {
    vector<vector<int> > board(n, vector<int> (n,0));
    solveNQueens(n, 0, board);
    return ans;
  }
};
