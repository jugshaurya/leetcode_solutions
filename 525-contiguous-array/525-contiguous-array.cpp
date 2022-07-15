class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();

        map<int, int> mp;
        mp[0] = -1;    

        int sum = 0;
        int ans = 0;
        for(int j=0; j<n; j++){
            sum += nums[j] == 0  ? -1 : 1;
            if(mp.count(sum) == 1){
                ans = max(ans, j - mp[sum]);
            }else mp[sum] = j;
        }

        return ans;
    }
};

// treat each 0 as -1
// find largest subarray with sum =0 and size atleast 2