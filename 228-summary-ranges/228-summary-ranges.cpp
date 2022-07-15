class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        
        int n = nums.size();
        if(n == 0) return {};
        int i = 0;
        for(int j = 1; j < n; j++){
            if(nums[j] == nums[j-1] + 1){
                continue;
            } else {
                string tmp = to_string(nums[i]);
                if(nums[i] != nums[j-1]) tmp += "->" + to_string(nums[j-1]);
                ans.push_back(tmp);
                i = j;
            }
        }
        
        string tmp = to_string(nums[i]);
        if(nums[i] != nums[n-1]) tmp += "->" + to_string(nums[n-1]);
        ans.push_back(tmp);
        
        return ans;
    }
};