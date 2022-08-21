class Solution {
public:
    vector<int> arr;
    vector<vector<int>> ans;
    
    void helper(int target, vector<int>& tmp, map<int, int>& mp) {
        if(target == 0) {
            ans.push_back(tmp);
            return;
        }

        if(target < 0) return;
        if(mp.empty()) return;
        
        auto [el, freq] = *mp.begin();    
        
        if(freq == 1) {
            mp.erase(el);
            helper(target, tmp, mp);
            
            tmp.push_back(el);
            helper(target - el, tmp, mp);
            tmp.pop_back();
            mp[el] = freq;
        }else {
            mp.erase(el);
            helper(target, tmp, mp);
            
            mp[el] = freq - 1;
            tmp.push_back(el);
            helper(target - el, tmp, mp);
            tmp.pop_back();
            mp[el] = freq;
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        arr = candidates;
        
        map<int, int> mp;
        for(auto x: arr) mp[x]++;
        
        vector<int> tmp;
        helper(target, tmp, mp);
        return ans;
    }
    
};