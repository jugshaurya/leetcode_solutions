class Solution {
public:
    
    // simply calculate the upward line end point difference.
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int i = 0;
        int j = 1;
        
        int ans = 0;
        while(j < n){
            if(prices[j] < prices[j-1]) {
                ans += prices[j-1] - prices[i];  
                i = j;
                j++;
            }else {
                j++;
            }
        }

        ans += prices[j-1] - prices[i];  
        return ans;
    }
};