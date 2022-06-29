
// Method 3: using PQ of size k, O(k + (n-k)logk)
// answer every query in O(1)
// optimized for answering queries/for stream of data.
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int> > pq; 
        for(int i=0; i<k; i++) pq.push(nums[i]);
        
        for(int i=k; i<n; i++){
            if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        
        return pq.top();
    }
};


// Method 2: can use QuickSelect Algorithm O(n*n)
// In worst Case: T(n) =  T(n-1)  + O(n) 
// class Solution {
// public:
//     int partition(vector<int>& nums, int s, int e) {
//         int pivot = nums[e];
//         int i = s;
//         for (int j = s; j <= e - 1; j++) 
//             if (nums[j] <= pivot) swap(nums[i++], nums[j]);
//         swap(nums[i], nums[e]);
//         return i;
//     }
    
//     int usingQuickSelect(vector<int>& nums, int k, int s, int e) {
//         int n = nums.size();
//         if(s > e) return -1;

//         int idx = partition(nums, s, e);
        
//         if(idx == n - k) return nums[idx];
//         if(idx < n - k) return usingQuickSelect(nums, k, idx + 1, e);
//         else return usingQuickSelect(nums, k, s, idx - 1);
//     }
    
//     int findKthLargest(vector<int>& nums, int k) {
//         return usingQuickSelect(nums, k, 0, nums.size()-1);
//     }
// };

// Method 1: can use PQ O(n + klogn)
// not optimized for answering queries/ for stream of data insertion
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int> pq(nums.begin(), nums.end());
//         while(--k) pq.pop();
//         return pq.top();
//     }
// };
