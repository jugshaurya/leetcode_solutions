// Logic: Every number can possibly become the root.
// Using Iterative code
class Solution {
public:
    int numTrees(int n) {
        int dp[n + 1];
        
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            dp[i] = 0;
            for(int j = 1; j <= i; j++){
                dp[i] += dp[j - 1] * dp[i - j]; 
            }
        }
        
        return dp[n];
    }
};

// using TopDown DP
// class Solution {
// public:
//     int dp[20];
//     int rec(int i){
//         if(i == 0) return 1;
        
//         if(dp[i] != -1) return dp[i];
        
//         int ans = 0;
//         for(int j = 1; j <= i; j++){
//             ans += rec(j - 1) * rec(i - j); 
//         }
        
//         return dp[i] = ans;
//     }

//     int numTrees(int n) {
//         memset(dp, -1, sizeof(dp));
//         return rec(n);
//     }
// };