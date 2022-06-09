class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        int s = 0;
        int e = n - 1;
        
        while(s<e){
            int mid = (s+e)/ 2;
            if(mid+1<n and mid-1 >=0 and arr[mid] != arr[mid+1] and arr[mid] != arr[mid-1]) return arr[mid];
            if(mid+1<n and arr[mid] == arr[mid+1] and (mid-s) % 2 == 0) s = mid + 2;
            if(mid+1<n and arr[mid] == arr[mid+1] and (mid-s) % 2 == 1) e = mid - 1; 
            if(mid-1>=0 and arr[mid] == arr[mid-1] and (mid-s) % 2 == 1) s = mid + 1;
            if(mid-1>=0 and arr[mid] == arr[mid-1] and (mid-s) % 2 == 0) e = mid - 2; 
            
        }
        
        if(s==e) return arr[s];
        assert("Code will never reach here!");
        return -1;
    }
};