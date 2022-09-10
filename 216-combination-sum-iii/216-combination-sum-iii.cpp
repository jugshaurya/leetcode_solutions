class Solution {
public:
    
    vector<vector<int>> ans;
    void rec(int i, int k, int sum, vector<int> &tmp) {
        if(k == 0 and sum == 0) {
            ans.push_back(tmp);
            return;
        }
        if(i == 10) return;
        if(sum < 0) return;
        if(k < 0) return;
        
        rec(i + 1, k, sum, tmp);
        tmp.push_back(i);
        rec(i + 1, k - 1, sum - i, tmp);
        tmp.pop_back();
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> tmp;
        rec(1, k, n, tmp);
        return ans;
    }
};