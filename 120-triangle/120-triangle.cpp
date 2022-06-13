class Solution {
public:
    
    int helper(vector<vector<int>>& triangle, int i, int j ){
        int n = triangle.size();
        if(i == n) return 0;
        return triangle[i][j] + min(helper(triangle, i+1, j), helper(triangle,i+1,j+1));
    }
    
    int helperDP(vector<vector<int>>& triangle){
        int n = triangle.size();
        vector<vector<int>> dp = triangle;
        
        for(int i = n-2; i >= 0; i--){
            for(int j = i; j >= 0; j--){
                dp[i][j] += min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        
        return dp[0][0];
    }
        
    int minimumTotal(vector<vector<int>>& triangle) {
        return helperDP(triangle);
    }
};