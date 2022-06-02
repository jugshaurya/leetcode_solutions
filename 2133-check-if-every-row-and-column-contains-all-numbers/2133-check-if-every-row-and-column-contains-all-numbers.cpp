class Solution {
  public:
  bool checkValid(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // check each row
    for (int i = 0; i < n; i++) {
      unordered_set<int> s;
      for (int j = 0; j < n; j++) s.insert(matrix[i][j]);
      if (s.size() != n) return false;
    }

    // check each col
    for (int j = 0; j < n; j++) {
      unordered_set<int> s;
      for (int i = 0; i < n; i++) s.insert(matrix[i][j]);
      if (s.size() != n) return false;
    }

    return true;
  }
};