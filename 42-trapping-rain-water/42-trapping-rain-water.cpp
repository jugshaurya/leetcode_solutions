// Method 2: Without extra space, Two Pointers
// // O(n) Time
// // O(1) space
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n - 1;
        
        int lmax = -1;
        int rmax = -1;
        
        int ans = 0;
        // using maths
        while(i <= j) {
            lmax = max(lmax, height[i]);
            rmax = max(rmax, height[j]);
            
            if(height[i] < height[j]){ // this works as well 
            // /* instead of this */ if(lmax < rmax){
                ans += lmax - height[i];
                i++;
            }else{
                ans += rmax - height[j];
                j--;
            }
        }
        
        return ans;
    }
};

// Method 1: using extra space
// // O(n) Time
// // O(n) space
// class Solution {
// public:
//     int trap(vector<int>& height) {
        
//         int n = height.size();
//         vector<int> lmax(n), rmax(n);
        
//         for(int i=0; i<n; i++){
//             if(i) lmax[i] = max(lmax[i-1], height[i]);
//             else lmax[i] = height[i];
//         }
        
//         for(int i=n-1; i>=0; i--){
//             if(i != n-1) rmax[i] = max(rmax[i+1], height[i]);
//             else rmax[i] = height[i];
//         }
        
//         int ans =0 ;
//         for(int i=0; i<n; i++){
//             int minBuilding
//             ans +=  min(lmax[i], rmax[i]) - height[i];
//         }
        
//         return ans;
//     }
// };