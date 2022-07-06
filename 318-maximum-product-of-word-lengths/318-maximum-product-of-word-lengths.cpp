// class Solution {
// public:
    
//     map<string, int> mp;
    
//     bool check(string &x, string& y){
        
//         vector<int> a(26, 0); 
//         vector<int> b(26, 0); 
        
//         for(auto ch: x) a[ch - 'a'] = 1;
//         for(auto ch: y) b[ch - 'a'] = 1;
        
//         for(int i=0; i<26; i++){
//             if(a[i] == b[i] and a[i] == 1) return false;
//         }        
//         return true;
//     }
    
//     int maxProduct(vector<string>& words) {
        
//         // for(auto x: words) {
//         //     int tmp = 0;
//         //     for(auto y: x) {
//         //         tmp = tmp | (1 << (y - 'a'));
//         //     }
//         //     mp[x] = tmp;
//         // }
        
//         int n = words.size();
//         int ans = 0;
//         for(int i = 0; i < n; i++){
//             for(int j = i + 1; j < n; j++){
//                 string x = words[i];
//                 string y = words[j];
//                 if(check(x, y)) {
//                     int len = x.size() * y.size();
//                     ans = max(ans, len);
//                 }
//             }
//         }
        
//         return ans;
//     }
// };


class Solution {
public:
    int maxProduct(vector<string>& words) {
        int best = 0;
        vector<int> bitsets(words.size());
        for (int i = 0; i < words.size(); i++) {
            string& word = words[i];
            int bitset = 0;
            for (char& c : word)
                bitset |= 1 << (c - 'a');
            for (int j = 0; j < i; j++)
                if ((bitsets[j] & bitset) == 0)
                    best = max(best, int(word.length() * words[j].length()));
            bitsets[i] = bitset;
        }
        return best;
    }
};