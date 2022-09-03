class Solution {
public:
    int n;
    int m;
    string a;
    string b;
    vector<vector<int>> dp;
    // int dp[2001][2001];
    
    bool helper(int i,  int j){
        if(i == n and j == m) return true;
        if(j == m) return false;
        if(i == n) {
            for(int k = j; k < m; k++) if(b[k] != '*') return false;
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];
        
        if(b[j] == '?') return dp[i][j] = helper(i + 1, j + 1);
        if(b[j] != '*' and a[i] == b[j]) return dp[i][j] = helper(i + 1, j + 1);
        if(b[j] != '*' and a[i] != b[j]) return dp[i][j] = false;
        
        // Transition of O(n) can be optimized to O(1)
        // for(int k = 0; i + k <= n; k++){
        //     if(helper(i + k, j + 1)) return dp[i][j] = true;
        // }
        // return dp[i][j] = false;
        
        return dp[i][j] = helper(i, j + 1) or helper(i + 1, j);
    }
    
    bool isMatch(string s, string p) {
        a = s;
        b = p;
        n = a.size();
        m = b.size();
        dp.resize(n + 1, vector<int>(m + 1, -1));
        // dp global array is not working in this question. 
        // memset(dp, -1, sizeof(dp));
        return helper(0, 0);   
    }
};

