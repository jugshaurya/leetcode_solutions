
class Solution {
  public:
  int count(int l, int s) {
        int count = 0;
      while(l!=0 and s!=0){
          int nl = max(s, l-s);
          int ns = min(s,l-s);
          count++;
          l = nl;
          s = ns;
      }
    return count;      
  }

  int countOperations(int num1, int num2) {
    if (num1 > num2)
      return count(num1, num2);
    return count(num2, num1);
  }
};