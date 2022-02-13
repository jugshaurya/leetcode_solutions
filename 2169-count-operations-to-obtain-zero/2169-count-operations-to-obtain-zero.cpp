
class Solution {
  public:
  int count(int a, int b) {
    if (b == 0)
      return 0;
    if (a > b)
      return 1 + count(b, a - b);
    return 1 + count(a, b - a);
  }

  int countOperations(int num1, int num2) {
    if (num1 > num2)
      return count(num1, num2);
    return count(num2, num1);
  }
};