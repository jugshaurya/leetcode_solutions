#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int bfs(vector<vector<int>>& grid, int i = 0, int j = 0) {
    
    int n = grid.size();
    queue<pair<int, int>> q;
    q.push({i, j});
    grid[i][j] = 2;

    int dx[] = {0, 1, 1, -1, 0, -1, -1, 1};
    int dy[] = {1, 1, 0, 1, -1, -1, 0, -1};

    while (!q.empty()) {
      auto [f, s] = q.front();
      q.pop();

      for (int k = 0; k < 8; k++) {
        int xx = f + dx[k];
        int yy = s + dy[k];
        if (xx >= 0 and xx < n and yy >= 0 and yy < n and grid[xx][yy] == 0) {
          grid[xx][yy] = grid[f][s] + 1;
          q.push({xx, yy});
        }
      }
    }

    int ans = grid[n - 1][n - 1];
    return ans == 0 ? -1: ans-1;

  }

  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    if (grid[0][0] != 0 or grid[n - 1][n - 1] != 0) return -1;
    return bfs(grid);
  }
};