
class Solution {
  public:
  bool isValidSudoku(vector<vector<char>>& board) {
    // check each row
    for (int i = 0; i < 9; i++) {
      set<char> s;
      for (int j = 0; j < 9; j++) {
        if (board[i][j] != '.') {
          if (s.find(board[i][j]) == s.end()) s.insert(board[i][j]);
          else return false;
        }
      }
    }

    // check each col
    for (int j = 0; j < 9; j++) {
      set<char> s;
      for (int i = 0; i < 9; i++) {
        if (board[i][j] != '.') { 
          if (s.find(board[i][j]) == s.end()) s.insert(board[i][j]);
          else return false;
        }
      }
    }

    // check each 3 by 3 rectangle
    for (int i = 0; i < 9; i += 3) {
      for (int j = 0; j < 9; j += 3) {
        // each rectangle
        set<char> s;
        for (int ii = i; ii < i + 3; ii++) {
          for (int jj = j; jj < j + 3; jj++) {
            if (board[ii][jj] != '.') {
              if (s.find(board[ii][jj]) == s.end()) s.insert(board[ii][jj]);
              else return false;
            }
          }
        }
      }
    }

    return true;
  }
};