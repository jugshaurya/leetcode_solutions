vector<string> dict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
class Solution {
  public:
  vector<string> letterCombinations(string digits) {
    vector<string> ans;
    int n = digits.size();
      
    if (n == 0) return ans;
    
    if (n == 1) {
      for (auto x : dict[digits[0] - '0']) {
        string tmp = "";
        tmp += x;
        ans.push_back(tmp);
      }
      return ans;
    }
      
    vector<string> subans = letterCombinations(digits.substr(1));
    for (auto x : dict[digits[0] - '0']) {
      for (auto y : subans) {
        string tmp;
        tmp += x;
        tmp += y;
        ans.push_back(tmp);
      }
    }

    return ans;
  }
};