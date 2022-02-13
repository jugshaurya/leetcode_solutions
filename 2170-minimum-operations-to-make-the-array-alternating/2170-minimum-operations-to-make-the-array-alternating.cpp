
class Solution {
  public:
  int minimumOperations(vector<int>& nums) {
    map<int, int> oddMap, evenMap;
    int n = nums.size();

    if (n == 1)
      return 0;
    if (n == 2) {
      if (nums[0] == nums[1])
        return 1;
      return 0;
    }
    set<int> s;
    for (int i = 0; i < n; i++) {
      if (i & 1)
        oddMap[nums[i]] += 1;
      else
        evenMap[nums[i]] += 1;
      s.insert(nums[i]);
    }

    if (s.size() == 1)
      return n / 2;

    vector<pair<int, int> > oddV, evenV;
    for (auto [f, s] : oddMap) {
      oddV.push_back({s, f});
    }
    for (auto [f, s] : evenMap) {
      evenV.push_back({s, f});
    }

    sort(oddV.begin(), oddV.end());
    reverse(oddV.begin(), oddV.end());
    sort(evenV.begin(), evenV.end());
    reverse(evenV.begin(), evenV.end());

    if (oddV[0].second != evenV[0].second) {
      return n - oddV[0].first - evenV[0].first;
    }

    if (evenV.size() == 1 and oddV.size() == 1) {
      if (evenV[0].second != oddV[0].second)
        return 0;
      return min(evenV[0].first, oddV[0].first);
    }

    if (oddV.size() == 1) {
      if (evenV[0].second != oddV[0].second) return n - evenV[0].first;
      int opt1 = evenV.size() + 1 + oddV[0].first - evenV[1].first;
      int opt2 = evenV.size() + 1 - evenV[1].first;
      return min(opt1, opt2);
    }

    if (evenV.size() == 1) {
      if (oddV[0].second != evenV[0].second) return n - oddV[0].first;
      int opt1 = oddV.size() + 1 + evenV[0].first - oddV[1].first;
      int opt2 = oddV.size() + 1 - oddV[1].first;
      return min(opt1, opt2);
    }


    return min(n - oddV[0].first - evenV[1].first, n - evenV[0].first - oddV[1].first);
  }
};