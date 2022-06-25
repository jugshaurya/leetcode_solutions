class Solution {
public:
    
    // for each bar in histogram, we find what if our rectangle contains this bar, 
    // what is the max area we can cover.
    
    // for each bar
    // find Prev Smaller
    // find next Smaller
    
    vector<int> getNextSmaller(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        vector<int> ans;
        for(int i=n-1; i>=0; i--){
            while(!s.empty() and nums[s.top()] >= nums[i]){
                s.pop();
            }
            
            if(s.empty()) {
                ans.push_back(n);
                s.push(i);
            }else{
                ans.push_back(s.top());
                s.push(i);
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    vector<int> getPrevSmaller(vector<int> &nums) {
        int n = nums.size();
        stack<int> s;
        vector<int> ans;

        for(int i=0; i < n; i++){
            while(!s.empty() and nums[s.top()] >= nums[i]){
                s.pop();
            }
            if(s.empty()) {
                s.push(i);
                ans.push_back(-1);
            }else{
                ans.push_back(s.top());
                s.push(i);
            }
        }
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> ps = getPrevSmaller(heights);        
        vector<int> ns = getNextSmaller(heights); 
        int n = heights.size();
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, (ns[i] - ps[i] - 1)*heights[i]);
        }
        
        return ans;
    }
};