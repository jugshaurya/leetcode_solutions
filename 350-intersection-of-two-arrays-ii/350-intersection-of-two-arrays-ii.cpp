// using twp pointers
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int n = nums1.size();
        int m = nums2.size();
        
        int i = 0; 
        int j = 0;
        
        vector<int> ans;
        while(i < n and j < m){
            if(nums1[i] == nums2[j]){
                ans.push_back(nums1[i]);
                i++;
                j++;
            } else if(nums1[i] < nums2[j]) i++;
            else j++;
        }
        
        return ans;
    }
    
};


// // using set
// class Solution {
// public:
//     vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

//         unordered_map<int, int> mp;
//         for(auto x: nums1) mp[x]++;
        
//         vector<int> ans;
//         for(auto x: nums2) {
//             if(mp.count(x) and mp[x]!=0){
//                 ans.push_back(x);
//                 mp[x]--;
//             }
//         }
        
//         return ans;
//     }
// };

        
