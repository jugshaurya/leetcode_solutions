const int NL = -1e9 - 1;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        // In an array there may exist atmax 2 elements occuring more than n/3 times
        // because n/3 + 1 + n/3 + 1  < n 
        // => 2n/3 + 2 <= n 
        // => 2 <= n - 2n/3 
        // => 2 <= n / 3 
        // => n >= 6 
        // holds true for all n >= 6 ∈ N
        
        // because of floor, n = 5 can also have 2 majority elements. 
        // because of floor, n = 4 can also have 2 majority elements.
        // because of floor, n = 3, can only have 1 majority element.
        // because of floor, n = 2, can have 2 majority element.
        // because of floor, n = 1 will have 1 majority element itself.
        
        int n = nums.size();
        
        int candidate1 = NL; 
        int candidate2 = NL;
        
        int cnt1 = 0;
        int cnt2 = 0;
        
        for(auto x: nums) {
            if(x == candidate1){
                cnt1++;
            } else if(x == candidate2){
                cnt2++;
            } else if(cnt1 == 0) {
                candidate1 = x;
                cnt1 = 1;
            } else if (cnt2 == 0){
                candidate2 = x;
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        
        vector<int> ans;
        cnt1 = 0;
        cnt2 = 0;
        for(auto x : nums) {
            if(x == candidate1) cnt1++;
            else if(x == candidate2) cnt2++;
        }
        
        if(cnt1 > n/3) ans.push_back(candidate1);
        if(cnt2 > n/3) ans.push_back(candidate2);
        return ans;
    }
};