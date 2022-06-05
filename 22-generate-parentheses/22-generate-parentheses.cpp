class Solution {
public:
    
    void helper(int n, vector<string> &ans, string s="", int openCount = 0, int closeCount = 0){
        if(openCount==closeCount and openCount==n){
            ans.push_back(s);
            return;
        }    
        
        if(openCount < n){
            helper(n, ans, s + "(", openCount+1, closeCount);
        }
        
        if(closeCount < openCount){
            helper(n, ans, s + ")", openCount, closeCount+1);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(n, ans);
        return ans;
    }
};