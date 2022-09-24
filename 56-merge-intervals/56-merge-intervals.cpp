class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        int s = intervals[0][0];
        int e = intervals[0][1];
        for(auto x: intervals) {
            int next_s = x[0];
            int next_e = x[1];
            if(next_s <= e){
                e = max(e, next_e);
            }else{
                ans.push_back({s, e});
                s = next_s;
                e = next_e;
            }
        }
        
        ans.push_back({s, e});
        
        return ans;
    }
};