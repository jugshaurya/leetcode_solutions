class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(), [](vector<int> a, vector<int> b){
            return a[1] > b[1];
        });
        
        int ans = 0;
        for(auto x: boxTypes){
            if(truckSize == 0) break;
            int boxesToBePutInTruck = min(truckSize, x[0]);
            ans += x[1] * boxesToBePutInTruck;
            truckSize -= boxesToBePutInTruck;
        }
        
        return ans;
    }
};