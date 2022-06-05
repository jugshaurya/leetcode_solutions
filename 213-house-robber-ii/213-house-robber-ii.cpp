class Solution {
public:
    int rob1(vector<int>& nums) {
        vector<int> dp(nums.size()+1, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        
        for(int i=2; i<=nums.size();i++){
            dp[i] = max(nums[i-1] + dp[i-2], dp[i-1]);
        }
        return dp[nums.size()];
    }

    void print(vector<int> nums){
        for(auto x: nums) cout<<x<<" ";
        cout<<endl;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        if(n==3) return max({nums[0], nums[1], nums[2]});
        
        // assuming house 0 will always be in answer.
        // implies house can't be house 1th and house (n-1)th.
        vector<int> temp = vector<int>(nums.begin()+2, nums.end()-1);
        int opt1 = nums[0] + rob1(temp);
        
        // assuming house (n-1) will always be in answer.
        // implies house can't be house 0th and house (n-2)th.
        temp = vector<int>(nums.begin()+1, nums.end()-2);
        int opt2 = nums[n-1] + rob1(temp);
        
        // assuming none of house 0 and (n-1)th will be in answer.
        // implies house can't be house 0th and house 2th.
        temp = vector<int>(nums.begin()+1, nums.end()-1);
        int opt3 = rob1(temp);
        
        return max({opt1,opt2,opt3});
        
    }
};