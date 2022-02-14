class Solution {

public:
    void print(vector<int>& beans){
        for(auto x: beans)cout<<x<<" ";
        cout<<endl;
    }
    
    long long minimumRemoval(vector<int>& beans) {
        
        sort(beans.begin(), beans.end());
        int n = beans.size(); 
        if(n==1) return 0;

        vector<long long> prefixSum(n+1);
        prefixSum[0] = 0;
        for(int i = 0; i<n; i++){
            prefixSum[i+1] = beans[i] + prefixSum[i];
        }
        
        // case if i don't make anything zero
        // answer would be minimum-beans[i], for all 0<=i<n
        long long ans = (prefixSum[n] - prefixSum[0]) - (long long)beans[0]*(n); 
        for(int i = 0; i<n-1;i++){
            long long temp = prefixSum[i+1];
            temp += (prefixSum[n] - prefixSum[i+1]) - (long long)beans[i+1]*(n-i-1);
            ans = min(ans, temp);
        }        
        return ans;
    }
};