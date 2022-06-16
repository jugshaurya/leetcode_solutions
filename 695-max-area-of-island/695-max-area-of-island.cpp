// movement vectors
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

class Solution {
public:
    int m;
    int n;
    
    int dfs(vector<vector<int>>& grid, int i, int j){
        grid[i][j] = 2;
        int ans = 0;
        for(int nbr = 0; nbr < 4; nbr++){
            int ii = i + dx[nbr]; 
            int jj = j + dy[nbr];
            if(ii>=0 and ii<m and jj>=0 and jj < n and grid[ii][jj] == 1){
                ans += dfs(grid, ii, jj);
            }
        }
        
        return ans + 1;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        m = grid.size();
        n = grid[0].size();
        
        int ans = 0;
        for(int i =0 ; i<m; i++){
            for(int j =0 ;j<n; j++){
                if(grid[i][j] == 1){
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }
        
        return ans;
    }
};