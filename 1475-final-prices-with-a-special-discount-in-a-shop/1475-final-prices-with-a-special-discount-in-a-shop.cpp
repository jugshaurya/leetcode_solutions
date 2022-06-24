class Solution {
public:

    // Next smaller or equal Element
    vector<int> getNextSmallerOrEqual(vector<int>& nums) {
        // Tip: Traverse from right
        int n = nums.size();
        stack<int> s;
        vector<int> ans;
        
        for(int i=n-1; i>=0; i--){
            
            while(!s.empty() and s.top() > nums[i]){
                s.pop();
            }
            
            if(s.empty()) {
                ans.push_back(0);
                s.push(nums[i]);
            }else{
                if(s.top() == nums[i]){
                    ans.push_back(nums[i]);
                }else{
                    ans.push_back(s.top());
                    s.push(nums[i]);
                }
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
     
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> discounts = getNextSmallerOrEqual(prices);
        
        for(int i=0;i<n;i++){
            prices[i] -= discounts[i];
        }
                
        return prices;
        
    }
};