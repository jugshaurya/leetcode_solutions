// Method1: Using STL
class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        
        if(it == nums.end() or *it!=target) return -1;
        return it - nums.begin();
    }
};

// Method2: from Scratch
// class Solution {
// public:
    
//     int search(vector<int>& arr, int target) {
//         int lo = 0;
//         int hi = arr.size()-1;
//         int ans = -1;
            
//         while(lo<=hi){
//             int mid = (lo+hi)/2;
//             if(arr[mid]==target) return mid;
//             if(arr[mid]<target){
//                 lo = mid+1;
//             }else{
//                 hi = mid-1;
//             }
//         }
        
//         return ans;
//     }
// };