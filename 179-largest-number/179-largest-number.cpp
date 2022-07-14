class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&](int a, int b){
            string as = to_string(a);
            string bs = to_string(b);
            return as + bs > bs + as;
        });
        
        string ans;
        for(auto x: nums){
            ans += to_string(x);
        }
        
        return ans[0] == '0' ? "0" : ans;
    }
};