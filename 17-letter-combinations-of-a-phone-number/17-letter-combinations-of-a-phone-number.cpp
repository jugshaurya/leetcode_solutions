
class Solution {
  public:
    vector<string> dict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    int n;
    string s;
    
    void rec(int i, string& tmp){
        if (i == n) {
            ans.push_back(tmp);
            return;
        }
        
        for (auto x : dict[s[i] - '0']){
            tmp += x;
            rec(i + 1, tmp);
            tmp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        this->s = digits;
        this->n = digits.size();
        
        if(n == 0) return {};
        
        string tmp;
        rec(0, tmp);
    
        return ans;
    }
};