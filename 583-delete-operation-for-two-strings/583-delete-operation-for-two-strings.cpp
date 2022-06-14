class Solution {
public:
    
    int helper(string& word1, string& word2,int i, int j){
        int n = word1.size();
        int m = word2.size();
        
        if(i == n) return m - j;
        if(j == m) return n - i;

        if(word1[i] == word2[j]) return helper(word1, word2, i+1, j+1);
        return 1 + min(helper(word1, word2, i+1, j), helper(word1, word2, i, j+1));
    }   
    
    int dp[505][505];
    int helperDP(string& word1, string& word2,int i, int j){
        int n = word1.size();
        int m = word2.size();
        
        if(i == n) return m - j;
        if(j == m) return n - i;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(word1[i] == word2[j]) return dp[i][j] = helperDP(word1, word2, i+1, j+1);
        return dp[i][j] = 1 + min(helperDP(word1, word2, i+1, j), helperDP(word1, word2, i, j+1));
    }
    
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        return helperDP(word1, word2, 0, 0);        
    }
};