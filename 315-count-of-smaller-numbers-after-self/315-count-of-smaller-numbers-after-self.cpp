#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define pii pair<int,int> 
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

// use policy based DS O(nlogn)
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        pbds s;        

        vector<int> ans;
        ans.push_back(0);
       
        s.insert({nums[n - 1], n-1});
        for(int i = n - 2; i >= 0; i--){
            int smallerCount = s.order_of_key({nums[i], i});
            ans.push_back(smallerCount);
            s.insert({nums[i], i});            
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// O(n*n) because of distance() begin O(n) for non-random access iterator

// class Solution {
// public:
//     vector<int> countSmaller(vector<int>& nums) {
//         int n = nums.size();
//         multiset<int> ms;

//         vector<int> ans;
//         ans.push_back(0);

//         ms.insert(nums[n - 1]);
//         for(int i = n - 2; i >= 0; i--){
//             auto it = ms.lower_bound(nums[i]);
//             int smallerCount = distance(ms.begin(), it);
//             ans.push_back(smallerCount);
//             ms.insert(nums[i]);            
//         }
        
//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };
