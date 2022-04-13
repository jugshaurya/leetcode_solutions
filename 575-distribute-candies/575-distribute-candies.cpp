class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> s(candyType.begin(), candyType.end());
        for(auto x: s) cout<<x<<" ";
        int n = candyType.size(); 
        int nn = s.size();
        if(n/2 < nn) return n/2;
        return nn;
    }
};