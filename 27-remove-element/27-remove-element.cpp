class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int n = nums.size();
        int i = 0;
        int j = 0;
        while(j<n){
            if(nums[j] != val) swap(nums[j++],nums[i++]);
            else j++;
        }
        
        return i;
    }
};