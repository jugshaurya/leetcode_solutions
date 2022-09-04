class Solution {
public:
    vector<int> arr;
    int n; 
    
    int rec(int l, int r) {
        if(l > r) return 0;
        
        int opt1 = arr[l] - rec(l + 1, r);
        int opt2 = arr[r] - rec(l, r - 1);
        
        return max(opt1, opt2);
    }

    bool PredictTheWinner(vector<int>& nums) {
        this->arr = nums;
        this->n = nums.size();

        return rec(0, n - 1) >= 0; 
    }
};