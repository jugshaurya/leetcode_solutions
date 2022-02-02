class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> temp = arr;
        sort(temp.begin(), temp.end(), [&](int a, int b){
            
            int aa = __builtin_popcount(a);
            int bb = __builtin_popcount(b);
            
            if(aa==bb) return a<b;
            return aa<bb;
        });
        
        return temp;
    }
};