class Solution {
public:
    
    void helper(int n, vector<string> &ans, string &s, int openCount = 0, int closeCount = 0){
        if(openCount==closeCount and openCount==n){
            ans.push_back(s);
            return;
        }    
        
        if(openCount < n){
            s.push_back('(');
            helper(n, ans, s, openCount+1, closeCount);
            s.pop_back();
        }
        
        if(closeCount < openCount){
            s.push_back(')');
            helper(n, ans, s , openCount, closeCount+1);
            s.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        helper(n, ans,s);
        return ans;
    }
};