class Solution {
public:
    
    // Find the greater element by iterating twice on nums array
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        vector<int> ans(n);
        
        for(int i = 2*n-1;i>=0;i--){
            int idx = i % n;
            while(!s.empty() and s.top() <= nums[idx]){
                s.pop();
            }
            if(s.empty()) {
                s.push(nums[idx]);
                ans[idx] = -1;
            }else{
                ans[idx] = s.top();
                s.push(nums[idx]);
            }
        }
        return ans;
    }
};