class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int count = 0;
        int pos = -1;
        for(auto x: nums){
            if(count == 0) pos = x;
            count += x == pos ? 1 :-1;
        }
        
        return pos;
    }
    
};