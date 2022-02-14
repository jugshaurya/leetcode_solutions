class Solution {

public:
    long long minimumRemoval(vector<int>& beans) {

        int n = beans.size(); 
        if(n == 1) return 0;

        sort(beans.begin(), beans.end());
        long long sum = accumulate(beans.begin(), beans.end(), 0L);
        
        long long ans = LLONG_MAX; // long long max, LONG_MAX also works
        for(int i = 0; i < n; i++){
            ans = min(ans, sum - (long long)beans[i]*(n-i));
        }        
        
        return ans;
    }
};