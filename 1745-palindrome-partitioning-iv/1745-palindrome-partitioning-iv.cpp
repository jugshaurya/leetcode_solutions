// Time: O(n^2)
// Space: O(n^2)
class Solution {
public:

    string s;
    int n;
    int dp[2001][2001];
    int isPal[2001][2001];

    bool isPalindrome(int i, int j){
        if(j <= i) return true;
        if(isPal[i][j] != -1) return isPal[i][j];
        return isPal[i][j] = s[i] == s[j] and isPalindrome(i + 1, j - 1);
    }
    
    int rec(int i, int k) {
        if(i == n and k == 0) return true;
        if(i == n and k > 0) return false;
        if(k <= 0) return false;
        
        if(dp[i][k] != -1) return dp[i][k];
        
        for (int j = i; j < n; j++) {
            if(isPalindrome(i, j)) {
                if(rec(j + 1, k - 1)) return dp[i][k] = true;
            }
        }
        
        return dp[i][k] = false;
    }
    
    bool checkPartitioning(string s) {
        this->s = s;
        this->n = s.size();

        memset(dp, -1, sizeof(dp));
        memset(isPal, -1, sizeof(isPal));
        return rec(0, 3);    
    }
};