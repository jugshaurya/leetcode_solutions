class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // find two biggest numbers and return therir product after reducing each element by one.
        
        int firstLargest = max(nums[0], nums[1]), secondLargest = min(nums[0], nums[1]);
        int n = nums.size(); 
        for(int i = 2; i<n; i++){
            if(nums[i] >= firstLargest) {
                secondLargest = firstLargest;
                firstLargest = nums[i];
            }else if(nums[i] > secondLargest){
                secondLargest = nums[i];
            }
        }
        
        return (firstLargest-1) * (secondLargest-1);
    }
};