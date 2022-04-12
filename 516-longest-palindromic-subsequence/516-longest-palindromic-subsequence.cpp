
class Solution {
public:
    int helper(string &a, int i, int j, vector<vector<int>> &memo){
        if(i>j) return 0;
        if(i==j) return 1;
        if(memo[i][j] != -1) return memo[i][j];
        if(a[i] == a[j]) return memo[i][j] = 2 + helper(a, i+1, j-1,memo);
        return memo[i][j] = max(helper(a, i, j - 1, memo), helper(a, i+1, j, memo));
    }
    
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> memo(n+1, vector<int>(n+1, -1));
        int ans =  helper(s, 0, s.size()-1, memo);
        return ans;
    }
};



// class Solution {
// public:
//    int memo(int i, int j, string &s, vector<vector<int>> &dp){
//         if(j<i) return 0;
//         if(j==i) return 1;
//         if(dp[i][j]!=-1) return dp[i][j];
//         if(s[i]==s[j]) return dp[i][j]=2+memo(i+1, j-1, s, dp);
//         else return  dp[i][j] = max(memo(i+1, j, s, dp), memo(i, j-1, s, dp));
//     }
    
//     int longestPalindromeSubseq(string s) {
//         int n=s.size();
//         vector<vector<int>> dp(n, vector<int>(n,-1));
//         return memo(0, n-1, s, dp);
//     }
// };