class Solution {
public:
    // O(num.length)
    vector<int> getNextGreaterElement(vector<int> num){
        int n = num.size();
        stack<int> s;
        
        vector<int> ans;
        // Tip: Traverse from right
        for(int i=n-1;i>=0;i--){
            while(!s.empty() and s.top() <= num[i]){
                s.pop();
            }
            if(s.empty()) {
                s.push(num[i]);
                ans.push_back(-1);
            }else{
                ans.push_back(s.top());
                s.push(num[i]);
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    // O(nums1.length + nums2.length)
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // O(nums2.length)
        map<int, int> mp;
        int n = nums2.size();
        for(int i =0; i<n; i++){
            mp[nums2[i]] = i;
        }
        
        // O(nums2.length)
        vector<int> nge = getNextGreaterElement(nums2);
        
        vector<int> ans;
        // O(nums1.length)
        for(auto x: nums1){
            ans.push_back(nge[mp[x]]);
        }
        
        return ans;
    }
};