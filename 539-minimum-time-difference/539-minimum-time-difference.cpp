class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for(auto x: timePoints) {
            int hr = (x[0]-'0')*10 + (x[1]-'0');    
            int minute = (x[3]-'0')*10 + (x[4]-'0'); 
            minutes.push_back(hr*60 + minute);
        }
        
        
        sort(minutes.begin(), minutes.end());   
        int mini = 1e9;
        int n = minutes.size();
        for(int i = 1; i<n;i++){
            mini = min(mini, minutes[i] - minutes[i-1]);
        }
        
        mini = min(mini, 1440-(minutes[n-1]-minutes[0]));
        return mini;
        
    }
};