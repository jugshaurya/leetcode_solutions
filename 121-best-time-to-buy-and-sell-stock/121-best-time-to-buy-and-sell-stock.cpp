class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Logic: start from the back and keep on taking max
        int n = prices.size();
        int maxx = prices[n-1];
        
        int ans = INT_MIN;
        for(int i = n-2; i>=0; i--){
            ans = max(ans, maxx - prices[i]);
            maxx = max(maxx, prices[i]);
        }
        
        return ans < 0 ? 0 : ans;
    }
};