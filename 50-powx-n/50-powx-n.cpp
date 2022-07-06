class Solution {
public:
    double myPow(double x, int n) {
        long long nn = n;
        if(nn < 0) {
            x = 1/x;
            nn = -(long)n;
        }

        double res = 1;
        while(nn) {
            if(nn & 1) res *= x; 
            x *= x;
            nn >>= 1;
        }
        
        return res;
    }
};