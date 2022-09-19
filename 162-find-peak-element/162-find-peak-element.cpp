class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = n - 1;

        while(s <= e) {
	        if(s == e) return s;
	        
            int mid = (s + e) / 2;
	        if(nums[mid + 1] > nums[mid]) s = mid + 1 ;
	        else e = mid;
	    }
        
        return s;
    }
};
