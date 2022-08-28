const int M = 1e9+7;

class Solution {
public:
    
    // f(n) = f(n-1) + f(n-2) + 2*g(n-2)
    // g(n) = g(n-1) + f(n-1);
    int numTilings(int n) {
            
        long f[1001]; 
        long g[1001]; 
        
        f[0] = g[0] = 0;
        f[1] = g[1] = 1;
        f[2] = g[2] = 2;
        
        for(int i = 3; i <= n; i++){
            f[i] = f[i - 1] + f[i - 2] + 2 * g[i - 2];
            f[i] %= M;
            g[i] = f[i - 1] + g[i - 1];
            g[i] %= M;
        }
        
        return f[n];
    }
};
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    