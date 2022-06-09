class Solution {
public:
    vector<int> dp;
    
    int helper(string s) { 
        int n = s.size();
        // Case: 0 length
        if(n == 0) return 1;
        
        // case: 1 length
        if(n == 1 and s[0] == '0') return 0; 
        if(n == 1) return 1; 
        
        // Case: atleast string is 2 length
        if(s[0] == '0') return 0;
        // Memoization
        if(dp[n] != -1) return dp[n];
        
        int ans = helper(s.substr(1));
        int num = (s[0]-'0')*10 + (s[1]-'0');
        
        if(num >= 1 and num <= 26){
            ans += helper(s.substr(2));
        }
        
        return dp[n] = ans;
        
    }
    
    int numDecodings(string s) {
        int n = s.size();
        dp.assign(n + 1, -1);
        return helper(s);
    }
};