class Solution {
public:
    
    int rec(int l, int r, vector<int> &nums){
      if(l>r) return 0;
      int opt1 = nums[l] - rec(l + 1, r,nums);
      int opt2 = nums[r] - rec(l, r-1,nums);
      return max(opt1, opt2);
    }

    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int score = rec(0,n-1, nums); 
        cout<<score<<endl;
        return score>=0;
    }
};