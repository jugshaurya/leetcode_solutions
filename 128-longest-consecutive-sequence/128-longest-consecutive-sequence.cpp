class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto x: nums) s.insert(x);
        
        int longestSeq = 0;
        for(auto x: nums) {
            if(s.count(x - 1)) continue;
            int tmp = x + 1;
            while(s.count(tmp) == 1) tmp++;
            longestSeq = max(longestSeq, tmp - x);
        }
        
        return longestSeq;
    }
};