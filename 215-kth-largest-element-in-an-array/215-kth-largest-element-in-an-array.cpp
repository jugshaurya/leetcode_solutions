class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
     
        // can use QuickSelect Algorithm
        
        // can use PQ
        priority_queue<int> pq(nums.begin(), nums.end());
        k--;
        while(k--){
            pq.pop();
        }
        
        return pq.top();
            
    }
};