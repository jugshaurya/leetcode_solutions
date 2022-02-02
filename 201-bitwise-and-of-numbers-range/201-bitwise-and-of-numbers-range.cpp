class Solution {
public:
    
    int countCommonPart(int a, int b){
        int cnt = 0;
        while(a!=b){
            a = a>>1;
            b = b>>1;
            cnt += 1;
        }
        return a<<cnt;
    }
    
    int rangeBitwiseAnd(int left, int right) {
        if(left==0 or right==0) return 0;
        if(left == right) return left;
        if(__builtin_clz(left) != __builtin_clz(right)) return 0;
        return countCommonPart(left,right);
    }
};