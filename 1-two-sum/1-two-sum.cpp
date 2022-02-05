class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int, int> m;
        for(int i=0;i<nums.size();i++){
            int val = target - nums[i];
            if(m.count(val)){
                return {m[val], i}; 
            }else{
                m[nums[i]] = i; 
            }
        }
        
        return ans;
    }
};