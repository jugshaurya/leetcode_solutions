class Solution {
public:
    int removePalindromeSub(string s) {
        string t = s;
        
        reverse(t.begin(), t.end());
        // if string is palindrome, onyl one operation is required.
        if(t==s) return 1;
        // otherwise, in 1 operation delete all a's and in 2nd all b's.
        return 2;
    }
};