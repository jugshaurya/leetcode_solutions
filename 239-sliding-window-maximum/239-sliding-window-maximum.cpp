class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        
        int i = 0;
        for(; i < k; i++) {
            while(!dq.empty() and nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i); 
        }

        vector<int> res;
        res.push_back(nums[dq.front()]);
        
        for(int i = k; i < n; i++) {
            while(!dq.empty() and dq.front() < i - k + 1) dq.pop_front();
            while(!dq.empty() and nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);
            res.push_back(nums[dq.front()]);
        }
        
        return res;
    }
};