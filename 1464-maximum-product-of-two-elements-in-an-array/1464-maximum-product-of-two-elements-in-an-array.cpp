class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // find two biggest numbers and return therir product after reducing each element by one.
        sort(nums.begin(), nums.end());
        int n = nums.size(); 
        return (nums[n-1]-1)*(nums[n-2]-1);
    }
};