class Solution {
public:
    
    int maxProduct(vector<string>& words) {
        int n = words.size();
        // Space: O(n)
        vector<int> mp(n, 0);

        // O(n*1000)
        for(int i=0; i<n; i++) {
            int tmp = 0;
            for(auto &y: words[i]) tmp |= (1 << (y - 'a'));
            mp[i] = tmp;
        }
        
        int ans = 0;
        // O(n^2)
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++){
                if((mp[i] & mp[j]) == 0) {
                    int len = words[i].size() * words[j].size();
                    ans = max(ans, len);
                }
            }
        }
        return ans;
    }
};