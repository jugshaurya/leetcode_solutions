class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int count = 0;
        int pos = -1;
        for(auto x: nums){
            if(count == 0) {pos = x; count+=1;}
            else {
                if(x == pos) count++;
                else count--;
            }
        }
        
        return pos;
    }
    
};