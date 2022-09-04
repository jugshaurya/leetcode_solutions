class Solution {
public:
    string s;
    int dp[1001][1001]; 
    
    // O(n^2)
    bool isPalindrome(int i, int j){
        if(i >= j) return true;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == s[j]) return dp[i][j] = isPalindrome(i + 1, j - 1);
        return dp[i][j] = false;
    }
    
    int countSubstrings(string s) {
        this->s = s;

        // O(n^2)
        memset(dp, -1, sizeof(dp));
        
        int ans = 0;
        // O(n^2) Amortized
        for(int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                if(isPalindrome(i, j)) ans++;
            }
        }
        
        return ans;
    }
};