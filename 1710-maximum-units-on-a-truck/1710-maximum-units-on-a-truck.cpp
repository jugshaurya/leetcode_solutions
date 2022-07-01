class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(), [](vector<int> a, vector<int> b){
            return a[1] > b[1];
        });
        
        int ans = 0;
        for(auto x: boxTypes){
            if(truckSize){
                if(x[0] > truckSize){
                    ans += x[1]*truckSize;
                    truckSize = 0;
                }else{
                    truckSize -= x[0];
                    ans += x[1]*x[0];
                }
            }else break;
        }
        
        return ans;
    }
};