class Solution {
public:
    int nextGreaterElement(int n) {
        string num = to_string(n);
        if(!next_permutation(num.begin(), num.end())){
            return -1;
        }
        
        long long int ans = 0;
        for(int i=0; num[i]!='\0'; i++){
            ans = ans*10 + (num[i]-'0'); 
        }
        
        if(ans > INT_MAX) return -1;
        return ans;
    }
};