class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans;
        for(auto x: nums){
            if(x<pivot){
                ans.push_back(x);
            }            
        }
        for(auto x: nums){
            if(x==pivot){
                ans.push_back(x);
            }            
        }
        for(auto x: nums){
            if(x>pivot){
                ans.push_back(x);
            }            
        }
        
        return ans;
        
    }
};