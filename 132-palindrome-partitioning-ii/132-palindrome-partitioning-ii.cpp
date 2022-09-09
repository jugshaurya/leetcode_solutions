// Method2: optimized Palindromic Function 
class Solution {
public:
    string s;
    int n;
    int dp[2002];
    int isPal[2002][2002];

    // O(n^2)
    bool isPalindrome(int i, int j){
        if(i >= j) return true;
        if(isPal[i][j] != -1) return isPal[i][j];
        if(s[i] == s[j]) return isPal[i][j] = isPalindrome(i + 1, j - 1);
        return isPal[i][j] = false;
    }

    // O(n^2)
    int rec (int i) {
        if(i == n) return 0;
        if(dp[i]!=-1) return dp[i];
        
        int ans = 1e9;
        for(int j = i; j < n; j++){ // O(n)
            if(isPal[i][j]) { // O(1)
                ans = min(ans, 1 + rec(j + 1));
            }
        }
        
        return dp[i] = ans;
    }
    
    int minCut(string s) {
        this->s = s;
        this->n = s.size();
        
        memset(dp, -1, sizeof(dp));
        memset(isPal, -1, sizeof(isPal));
        
        int ans = 0;
        // O(n^2) Amortized
        for(int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                isPalindrome(i, j);
            }
        }
        
        return rec(0) - 1;
    }
};


// Method1: Not optimized Palindromic Function 
// class Solution {
// public:
//     string s;
//     int n;
//     int dp[2002];
    
//     bool isPalindrome(int i, int j) {
//         if(i >= j) return true;    
//         return s[i] == s[j] and isPalindrome(i + 1, j - 1); 
//     }
    
//     // O(n^3)
//     int rec (int i) {
//         if(i == n) return 0;
//         if(dp[i]!=-1) return dp[i];
        
//         int ans = 1e9;
//         for(int j = i; j < n; j++){ // O(n)
//             if(isPalindrome(i, j)) { // O(n)
//                 ans = min(ans, 1 + rec(j + 1));
//             }
//         }
        
//         return dp[i] = ans;
//     }
    
//     int minCut(string s) {
//         this->s = s;
//         this->n = s.size();
        
//         memset(dp, -1, sizeof(dp));
//         return rec(0) - 1;
//     }
// };

