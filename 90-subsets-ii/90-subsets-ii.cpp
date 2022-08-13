// Method: without storing all generated substes in a set. 

class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int> &subans, map<int, int> &mp){
        if(mp.empty()) {
            ans.push_back(subans);
            return;
        }
        
        auto [key, val] = *mp.begin();
        
        // frequency is one
        if(val == 1) {
            mp.erase(key);
            helper(subans, mp);
            
            subans.push_back(key);
            helper(subans, mp);
            subans.pop_back();
            
            mp[key] = val; 
        }else {
            mp[key] -= 1;
            subans.push_back(key);
            helper(subans, mp);
            subans.pop_back();
            
            mp.erase(key);
            helper(subans, mp);
            mp[key] = val;
        }
        
        return;
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
                
        map<int, int> mp;
        for(auto x: nums) mp[x]++;
        
        vector<int> subans;
        helper(subans, mp);
        
        return ans;
    }
};
