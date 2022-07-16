class Solution {
public:
    
    int getNumber(string &s){
        int ans = 0;
        for(auto ch: s){
            int digit = ch - '0';
            ans = ans * 10 + digit;
        }
        return ans;
    }
    
    int compareVersion(string version1, string version2) {
        
        int n1 = version1.size();
        int n2 = version2.size();
        
        int i = 0;
        int j = 0; 
        
        while(i < n1 and j < n2){
            string tmp1 ;
            while(i < n1 and version1[i] != '.'){
                tmp1 += version1[i++];
            }
            i++;
            int tmp1Int = getNumber(tmp1); 
            
            string tmp2 ;
            while(j < n2 and version2[j] != '.'){
                tmp2 += version2[j++];
            }
            j++;
            int tmp2Int = getNumber(tmp2); 
            
            
            if(tmp1Int > tmp2Int) return 1;
            if(tmp1Int < tmp2Int) return -1;
        }
        
        while(i < n1){
            string tmp1;
            while(i < n1 and version1[i] != '.'){
                tmp1 += version1[i++];
            }
            i++;
            
            int tmp1Int = getNumber(tmp1); 
            if(tmp1Int != 0) return 1;
        }
        
        while(j < n2){
            string tmp2;
            while(j < n2 and version2[j] != '.'){
                tmp2 += version2[j++];
            }
            j++;
            
            int tmp2Int = getNumber(tmp2); 
            if(tmp2Int != 0) return -1;
        }
        
        return 0;
    }
};