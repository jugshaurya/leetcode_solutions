class Solution {
public:
    
    int partition(vector<int>& nums, int s, int e) {
        
        int pivot = nums[e];
        int i = s;
        
        for (int j = s; j <= e - 1; j++) 
            if (nums[j] <= pivot) swap(nums[i++], nums[j]);

        swap(nums[i], nums[e]);
        return i;
    }
    
    int usingQuickSelect(vector<int>& nums, int k, int s, int e) {
        int n = nums.size();
        int idx = partition(nums, s, e);
        if(idx == n - k) return nums[idx];
        if(idx < n - k) return usingQuickSelect(nums, k, idx + 1, e);
        return usingQuickSelect(nums, k, s, idx - 1);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        // Method 1: can use QuickSelect Algorithm
        return usingQuickSelect(nums, k, 0, nums.size()-1);

        // Method 2: can use PQ
        // priority_queue<int> pq(nums.begin(), nums.end());
        // k--; 
        // while(k--){
        //     pq.pop();
        // }
        // return pq.top();
    }
};