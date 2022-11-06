// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int s = 0;
        int e = n;
        int ans = 1;
        int cnt = 32;
        while(cnt--) {
            int mid = s+ (e - s) / 2;
            if(isBadVersion(mid)){
                ans = mid;
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        
        return ans;
    }
};