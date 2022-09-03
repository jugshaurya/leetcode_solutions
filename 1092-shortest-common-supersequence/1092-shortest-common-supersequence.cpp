class Solution {
public:
    int n;
    int m;
    string a;
    string b;

    int dp[1001][1001];
    int rec(int i, int j) {
        if(i == n) return m - j;
        if(j == m) return n - i;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(a[i] == b[j]) return dp[i][j] = 1 + rec(i + 1, j + 1);
        return dp[i][j] = 1 + min(rec(i +  1, j), rec(i, j + 1)); 
    }

    void printSCS(int i, int j, string &ans){
        if(i == n) {
            ans += b.substr(j);
            return;
        };

        if(j == m) {
            ans += a.substr(i);
            return;
        };
        
        if(a[i] == b[j]) {
            ans += a[i];
            printSCS(i + 1, j + 1,ans);
        }else {
            if(rec(i +  1, j) < rec(i, j + 1)){
                ans += a[i];
                printSCS(i + 1, j, ans);
            }else{
                ans += b[j];
                printSCS(i, j + 1, ans);
            }
        }
    }

    string shortestCommonSupersequence(string str1, string str2) {
        a = str1;
        n = str1.size();
        b = str2;
        m = str2.size();
        
        memset(dp, -1, sizeof(dp));
        rec(0, 0);
        string ans;
        printSCS(0, 0, ans);
        return ans;
        
    }
};

