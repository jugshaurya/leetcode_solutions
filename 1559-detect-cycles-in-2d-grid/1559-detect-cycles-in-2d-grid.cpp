
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

class Solution {
  public:
  // finding the cycle in directed graph or undirected graph.(both works here.)
  // pi and pj => parent of (i,j)
  bool cyclePresent(vector<vector<char>>& grid, int i, int j, int pi, int pj) {
    char val = grid[i][j];
    grid[i][j] = (val - 32);

    int m = grid.size();
    int n = grid[0].size();
    for (int k = 0; k < 4; k++) {
      int ii = i + dx[k];
      int jj = j + dy[k];
      if (ii >= 0 and ii < m and jj >= 0 and jj < n) {
        if (grid[ii][jj] == val) {
          if (cyclePresent(grid, ii, jj, i, j)){
            return true;
          }
        }
        else if (grid[ii][jj] == (val - 32) and ii != pi and jj != pj){
          return true;
        }
      }
    }
        
    return false;
  }

  bool containsCycle(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        // marking cell visited using capital letter of value at (i,j)`.
        if (grid[i][j] >= 'a' and grid[i][j] <= 'z' and cyclePresent(grid, i, j, -1, -1)){
          return true;
        }
        
          // for (int ih = 0; ih < m; ih++) {
          // for (int jh = 0; jh < n; jh++) {
          //       cout<<grid[ih][jh]<<" ";
          // } cout<<endl;}
          // cout<<endl;
          
      }
    }
    return false;
  }
};