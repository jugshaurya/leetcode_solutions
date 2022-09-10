class Solution {
public:
    vector<int> arr;
    vector<vector<int>> ans;
    int n;
    
    void helper(int i, int target, vector<int>& tmp) {
        if(i == n and target == 0) {
            ans.push_back(tmp);
            return;
        }
        
        if(i == n) return;
        if(target < 0) return;
        
        helper(i + 1, target, tmp);
        tmp.push_back(arr[i]);
        helper(i, target - arr[i], tmp);
        tmp.pop_back();
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->arr = candidates;
        this->n = arr.size();
        vector<int> tmp;
        helper(0, target, tmp);
        return ans;
    }
};