class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        set<int> v;
        for(auto x: edges){
            if(v.count(x[0])) return x[0];
            if(v.count(x[1])) return x[1];
            v.insert(x[0]);
            v.insert(x[1]);
        }

        return -1;
    }
};