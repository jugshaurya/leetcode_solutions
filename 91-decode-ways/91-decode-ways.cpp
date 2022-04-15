class Solution {
  public:
  
  int dp[5005];
  string s;
  int ways(int i = 0) {
    if (i == s.size()) return 1;
    if (s[i] == '0') return 0;
    if (i + 1 == s.size() and s[i] == '0') return 0;
    if (i + 1 == s.size() and s[i] != '0') return 1;

    if (dp[i] != -1) return dp[i];

    int ans = 0;
    if (s[i] >= '1' and s[i] <= '9') ans += ways(i + 1);
    if (s[i] == '1') ans += ways(i + 2);
    if (i + 1 < s.size() and (s[i] == '2' and s[i + 1] <= '6')) ans += ways(i + 2);
    return dp[i] = ans;
  }

  int numDecodings(string str) {
    s = str;
    memset(dp, -1, sizeof(dp));
    return ways();
  }
};