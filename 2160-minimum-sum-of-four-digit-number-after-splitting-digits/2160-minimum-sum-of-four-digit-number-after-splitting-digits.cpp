class Solution {
public:
    int minimumSum(int num) {
        vector<int> d;
        while(num){
          d.push_back(num%10);
          num/=10;
        }
        sort(d.begin(), d.end());
        return d[0]*10 + d[2] + d[1]*10+d[3];
    }
};