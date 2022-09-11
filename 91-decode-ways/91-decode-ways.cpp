class Solution {
public:
    string s;
    int n;
    int dp[101];
    
    int rec(int i){
        if(i == n) return 1;
        if(s[i] == '0') return dp[i] = 0;

        if(dp[i] != -1) return dp[i];
            
        int ans = rec(i + 1);
        if(i + 1 < n) {
            int number = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if(number >= 1 and number <= 26) ans += rec(i + 2);
        }
        
        return dp[i] = ans;
    }
    
    int numDecodings(string s) {
        this->s = s;    
        this->n = s.size();    

        memset(dp, -1, sizeof(dp));
        return rec(0);
    }
};