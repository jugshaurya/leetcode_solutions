class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        
        sort(nums.begin(),nums.end(), [](string a, string b){
            if(a.size() > b.size()) return false;
            if(b.size() > a.size()) return true;

            // sizes are equal
            for(int i = 0;a[i]!='\0';i++){
                if(a[i] < b[i]) return true;
                if(a[i] > b[i]) return false;
            }
            
            return false;
        });
        
        int n = nums.size();
        return nums[n - k];
            
            
    }
};