// Method 1: using 4 states
// O(n) transitions
// Time complexity: O(n^5)
// Space complexity: O(n^4)

class Solution {
   public:
    string a, b;
    int n, m;
    int dp[31][31][31][31];
    
    bool rec(int l1, int r1, int l2, int r2) {

        if(l1 > r1) return true;
        if(l1 == r1) return a[l1] == b[l2];
        
        if(dp[l1][r1][l2][r2]!=-1) return dp[l1][r1][l2][r2];

        bool ans = false;
        int len = r1 - l1 + 1;
        for (int i = 0; i < len - 1; i++) {
            ans |= rec(l1, l1 + i, l2, l2 + i) and rec(l1 + i + 1, r1, l2 + i + 1, r2);
            ans |= rec(l1, l1 + i, r2 - i , r2) and rec(l1 + i + 1, r1, l2, r2 - i - 1);
        }
        return dp[l1][r1][l2][r2] =ans;
    }

    bool isScramble(string s1, string s2) {
        this->n = s1.size();
        this->m = s2.size();
        this->a = s1;
        this->b = s2;
        
        memset(dp,-1,sizeof(dp));
        
        if(n != m) assert("Invalid Input");
        return rec(0, n - 1, 0, m - 1);
    }
};