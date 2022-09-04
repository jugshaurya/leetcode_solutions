// Method 2: optimized using extra O(n^2) space 
// Time = O(n^2)
class Solution{
public:
    string s;
    int dp[1001][1001]; 
    
    bool isPalindrome(int i, int j){
        if(i >= j) return true;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == s[j]) return dp[i][j] = isPalindrome(i + 1, j - 1);
        return dp[i][j] = false;
    }
    
    string longestPalindrome(string s) {
        this->s = s;
        memset(dp, -1, sizeof(dp));
        
        int ans = 0;
        string res;
        for(int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                if(isPalindrome(i, j)) {
                    if(ans < j - i + 1){
                        ans = j - i + 1;
                        res = s.substr(i, ans);
                    }
                }
            }
        }
        
        return res;
    }
};

// Method 1: Brute Force O(n^3)
// class Solution {
// public:
    // bool isPalindrome(string &s, int i, int j){
    //     string t = s.substr(i, j - i + 1);
    //     string tt = t;
    //     reverse(t.begin(), t.end());
    //     return t == tt;                
    // }
    
    // string longestPalindrome(string s) {
    //     int n = s.size();
    //     int maxx = 0;
    //     string ans;
    //     for(int i = 0; i < n; i++){
    //         for(int j = i; j < n; j++){
    //             if(isPalindrome(s, i, j)){
    //                 if(j - i + 1 > maxx){
    //                     maxx = j - i + 1;
    //                     ans = s.substr(i, j - i + 1);
    //                 }
    //             }
    //         }
    //     }
    
    //     return ans;
    // }
// };
