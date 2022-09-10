class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void rec(int i, int k, vector<int>& tmp){
        
        if(k == 0) {
            ans.push_back(tmp);
            return;
        }
        
        if(i == n + 1) return;
        
        rec(i + 1, k, tmp);
        tmp.push_back(i);
        rec(i + 1, k - 1, tmp);
        tmp.pop_back();
    }
    
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        vector<int> tmp;
        rec(1, k ,tmp);
        return ans;
    }
};