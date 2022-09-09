class Solution {
public:
    vector<vector<string>> ans;
    string s;
    int n;
    
    bool isPalindrome(int i, int j) {
        if(i >= j) return true;    
        return s[i] == s[j] and isPalindrome(i + 1, j - 1); 
    }
    
    void rec(int i, vector<string>& tmp) {
        if(i == n) {
            ans.push_back(tmp);
            return;
        };
        
        for(int j = i; j < n; j++){
            if(isPalindrome(i, j)) {
                tmp.push_back(s.substr(i, j - i + 1));
                rec(j + 1, tmp);
                tmp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        this->s = s;
        this->n = s.size();
        
        vector<string> tmp;
        rec(0, tmp);
        return ans;
    }
};