class Solution {
public:
    
    int getSumOfSquares(int n){
      int sum = 0;
      while(n){
        sum += (n%10)*(n%10); 
        n/=10;
      }
      
      return sum;
    }
  
    bool isHappy(int n) {
      int t = n;
      int cnt = 0; 
      while(cnt<100){
        cnt++;
        t = getSumOfSquares(t);
        if(t==1) return true;
      }
      
      return false;
    }
};