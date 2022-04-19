class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missingNumber = 0;
        int n = nums.size();
        for(int i=0;i<=n;i++) missingNumber^=i;
        for(int i=0;i<n;i++) missingNumber^=nums[i];
        return missingNumber;
    }
};