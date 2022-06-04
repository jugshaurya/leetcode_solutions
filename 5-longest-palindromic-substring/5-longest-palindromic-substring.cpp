class Solution {
public:
    // Brute Force O(n^3)
    // bool isPalindrome(string &s, int i, int j){
    //     // Brute force O(n)
    //     string t = s.substr(i, j-i+1);
    //     string tt = t;
    //     reverse(t.begin(), t.end());
    //     return t == tt;                
    // }
    // string longestPalindrome(string s) {
    //     int n = s.size();
    //     int maxx = 0;
    //     string ans;
    //     for(int i=0;i<n;i++){
    //         for(int j=i;j<n;j++){
    //             if(isPalindrome(s,i,j)){
    //                 if(j-i+1 > maxx){
    //                     maxx = j-i+1;
    //                     ans = s.substr(i,j-i+1);
    //                 }
    //             }
    //         }
    //     }
    //     return ans;
    // }

    // optimized using extra O(n^2) space => Time = O(n^2)
    string longestPalindrome(string s) {
        int n = s.size();
        int maxx = 0;
        string ans;
        vector<vector<int>> isPal(n, vector<int>(n,0));
        
        // every single element is a palindrome in itself.
        for(int i=0;i<n;i++){
            isPal[i][i] = 1; 
        }
        
        // filling rest of the stuff
        // start is [0][i]
        for(int i=1;i<n;i++){
            for (int j =0;j<n;j++){
                // element [0+j][i+j]
                int row = 0+j;
                int col = i+j;
                if(col<n){
                    isPal[row][col] = s[row] != s[col] ? 0 : (row+1==col ? 1 : isPal[row+1][col-1]);   
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPal[i][j] == 1){
                    if(j-i+1 > maxx){
                        maxx = j-i+1;
                        ans = s.substr(i,j-i+1);
                    }
                }
            }
        }
        return ans;
    }
    
};