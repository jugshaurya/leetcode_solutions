// Method 1
// class Solution {
// public:
//     vector<int> countBits(int n) {
//         // O(n)
//         vector<int> dp(n+1,0);
//         for(int i = 1; i <= n; i++){
//             dp[i] = dp[i >> 1] + (i & 1);
//         }
        
//         return dp;
//     }
// };

// Method 2
class Solution {
public:
    vector<int> countBits(int n) {
        // O(n)
        vector<int> dp(n+1,0);
        for(int i = 1; i <= n; i++){
            dp[i] = dp[i & (i - 1)] + 1;
        }
        
        return dp;
    }
};