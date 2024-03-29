// Can be think of LR Dp
// but R is not changing

// So can be think in terms of Form 2 DP, DP(ending at i).
class Solution {
public:
    int k;
    vector<int> arr;
    int n;
    int dp[501];
    
    int rec(int l, int r){
        if (l > r) return 0;
        if (l >= r) return arr[l];
            
        if(dp[l] != -1) return dp[l];
        
        int ans = 0;
        int maxSoFar = 0;
        for (int i = 0; i < k and l + i < n; i++) {
            maxSoFar = max(maxSoFar, arr[l + i]);
            ans = max(ans, (i + 1) * maxSoFar + rec(l + i + 1, r));
        }

        return dp[l] = ans;	
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        this-> k = k;
        this-> arr = arr;
        this->n = arr.size();
        
        memset(dp, -1, sizeof(dp));
        return rec(0, n - 1);
    }
};