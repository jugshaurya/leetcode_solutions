class Solution {
public:
    
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> mp(n, 0);

        for(int i=0; i<n; i++) {
            int tmp = 0;
            for(auto &y: words[i]) tmp |= (1 << (y - 'a'));
            mp[i] = tmp;
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++){
                if((mp[i] & mp[j]) == 0) {
                    int len = words[i].size() * words[j].size();
                    ans = max(ans, len);
                }
            }
        }
        
        return ans;
    }
};


// class Solution {
// public:
//     int maxProduct(vector<string>& words) {
//         int best = 0;
//         vector<int> bitsets(words.size());
//         for (int i = 0; i < words.size(); i++) {
//             string& word = words[i];
//             int bitset = 0;
//             for (char& c : word)
//                 bitset |= 1 << (c - 'a');
//             for (int j = 0; j < i; j++)
//                 if ((bitsets[j] & bitset) == 0)
//                     best = max(best, int(word.length() * words[j].length()));
//             bitsets[i] = bitset;
//         }
//         return best;
//     }
// };