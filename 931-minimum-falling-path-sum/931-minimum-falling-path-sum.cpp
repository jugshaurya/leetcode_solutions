class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        vector<vector<int>> dp (2, vector<int>(n, 0));
        
        for(int j = 0; j < n; j++){
            dp[(n - 1)&1][j] = matrix[n - 1][j];
        }
        
        for(int i = n - 2; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--){
                dp[i&1][j] = dp[(i + 1)&1][j];
                if(j + 1 < n) dp[i&1][j] = min(dp[i&1][j], dp[(i + 1)&1][j + 1]);
                if(j - 1 >= 0) dp[i&1][j] = min(dp[i&1][j], dp[(i + 1)&1][j - 1]);

                dp[i&1][j] += matrix[i][j];
            }
        }
        
        int ans = INT_MAX;
        for(int j =0; j < n; j++){
            ans = min(ans, dp[0][j]);
        }
        
        return ans;
    }
};