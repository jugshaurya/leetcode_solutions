class Solution {
  public:
  void printBoard(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        cout << board[i][j] << " ";
      }
      cout << endl;
    }
  }

  bool canPlaceK(vector<vector<char>>& board, int i, int j, char k) {
    // check for row and col
    for (int l = 0; l < 9; l++) {
      if (board[i][l] == k)
        return false;
      if (board[l][j] == k)
        return false;
    }

    // check for 3x3 grid
    int si = i / 3;
    int sj = j / 3;
    for (int li = si * 3; li < si * 3 + 3; li++)
      for (int lj = sj * 3; lj < sj * 3 + 3; lj++)
        if (board[li][lj] == k)
          return false;

    return true;
  }

  bool solveSudokuHelper(vector<vector<char>>& board, int i, int j) {
    if (i == 9)
      return true;

    if (j == 9)
      return solveSudokuHelper(board, i + 1, 0);

    if (board[i][j] != '.')
      return solveSudokuHelper(board, i, j + 1);

    for (int k = 1; k <= 9; k++) {
      if (canPlaceK(board, i, j, (k + '0'))) {
        board[i][j] = k + '0';
        if (solveSudokuHelper(board, i, j + 1))
          return true;
      }
    }

    board[i][j] = '.';
    return false;
  }

  void solveSudoku(vector<vector<char>>& board) {
    solveSudokuHelper(board, 0, 0);
    // printBoard(board);
  }
};
