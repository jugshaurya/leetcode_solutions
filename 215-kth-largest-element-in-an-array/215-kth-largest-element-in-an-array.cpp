// Method 1: can use QuickSelect Algorithm O(n*n)
// In worst Case: T(n) =  T(n-1)  + O(n) 
class Solution {
public:
    int partition(vector<int>& nums, int s, int e) {
        int pivot = nums[e];
        int i = s;
        int j = s;
        while(j <= e){
            if(nums[j] <= pivot){
                swap(nums[i++], nums[j]);
            }
            j++;
        }
        return i-1;
    }
    
    int usingQuickSelect(vector<int>& nums, int k, int s, int e) {
        int n = nums.size();
        if(s > e) return -1;

        int idx = partition(nums, s, e);
        
        if(idx == n - k) return nums[idx];
        if(idx < n - k) return usingQuickSelect(nums, k, idx + 1, e);
        else return usingQuickSelect(nums, k, s, idx - 1);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return usingQuickSelect(nums, k, 0, nums.size()-1);
    }
};

// Method 2: can use PQ O(n + klogn)
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int> pq(nums.begin(), nums.end());
//         while(--k) pq.pop();
//         return pq.top();
//     }
// };

