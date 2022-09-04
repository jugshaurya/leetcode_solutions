// Method 3: constant space, using Expand around center
// Time = O(n^2)
class Solution{
public:
    int n;
    string s;
    
    string expandAroundCenter(int i, int j){
        while(i >= 0 and j < n and s[i] == s[j]){
            i--;
            j++;
        }
        return s.substr(i + 1, j - i - 1);
    }
    
    string longestPalindrome(string s) {
        this -> n = s.size();
        this->s = s;
        int ansLen = 0;
        string ansStr;
        
        for(int i = 0; i < n; i++){
            string opt1 = expandAroundCenter(i, i);
            string opt2 = expandAroundCenter(i, i + 1);
            
            if(opt1.size() > ansLen) {
                ansLen = opt1.size();
                ansStr = opt1;
            }
            
            if(opt2.size() > ansLen) {
                ansLen = opt2.size();
                ansStr = opt2;
            }
        }
        
        return ansStr;
    }
};

// Method 2: optimized using extra O(n^2) space 
// Time = O(n^2)
// class Solution{
// public:
//     string s;
//     int dp[1001][1001]; 
    
//     // O(n^2)
//     bool isPalindrome(int i, int j){
//         if(i >= j) return true;
//         if(dp[i][j] != -1) return dp[i][j];
        
//         if(s[i] == s[j]) return dp[i][j] = isPalindrome(i + 1, j - 1);
//         return dp[i][j] = false;
//     }
    
//     string longestPalindrome(string s) {
//         this->s = s;

//         // O(n^2)
//         memset(dp, -1, sizeof(dp));
        
//         int ans = 0;
//         string res;
        
//         // O(n^2)
//         for(int i = 0; i < s.size(); i++) {
//             for (int j = i; j < s.size(); j++) {
//                 if(isPalindrome(i, j)) { // O(1)
//                     if(ans < j - i + 1){
//                         ans = j - i + 1;
//                         res = s.substr(i, ans);
//                     }
//                 }
//             }
//         }
        
//         return res;
//     }
// };

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
